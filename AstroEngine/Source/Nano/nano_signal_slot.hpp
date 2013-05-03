/*------------------------------------------------------------------------------
----------------------// Version: 1.05 // License: MIT //-----------------------
--------------------------------------------------------------------------------

Copyright (c) 2012-2013 ApEk

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.

--------------------------------------------------------------------------------
----------------------// Version: 1.05 // License: MIT //-----------------------
------------------------------------------------------------------------------*/

#ifndef NANO_SIGNAL_SLOT_HPP
#define NANO_SIGNAL_SLOT_HPP

#include <unordered_map>

namespace Nano
{

namespace Core
{

typedef std::pair<std::uintptr_t, std::uintptr_t> delegate_key_t;

struct key_hash
{
    std::size_t operator() (delegate_key_t const& key) const
    {
        return key.first + 0x9E3779B9 + (key.second << 6) + (key.second >> 2);
    }
};

//------------------------------------------------------------------------------

template <typename T> class table_wrap
{
    typedef std::unordered_map<delegate_key_t, T, key_hash> table_t;

    table_t m_table;

    public:

    inline void insert(delegate_key_t const& key, T const& value)
    {
        m_table.emplace(key, value);
    }
    inline void remove(delegate_key_t const& key)
    {
        m_table.erase(key);
    }
    inline typename table_t::const_iterator begin() const
    {
        return m_table.cbegin();
    }
    inline typename table_t::const_iterator end() const
    {
        return m_table.cend();
    }
};

} // namespace Core ------------------------------------------------------------

using Core::delegate_key_t;

struct tracked
{
    Core::table_wrap<tracked*> tracked_connections;

    virtual void remove_tracked(delegate_key_t const& key)
    {
        tracked_connections.remove(key);
    }
    virtual ~tracked ( )
    {
        for (auto const& connection : tracked_connections)
        {
            connection.second->remove_tracked(connection.first);
        }
    }
};

//------------------------------------------------------------------------------

template <typename... Args> class signal { signal() = delete; };
template <typename Re_t, typename... Args> class signal<Re_t(Args...)> : tracked
{
    class function
    {
        void *m_this_ptr = nullptr;
        Re_t(*m_stub_ptr)(void*, Args...);

        public:

        template <Re_t (*FunPtr)(Args...)>
        static inline function bind()
        {
            function delegate;
            delegate.m_stub_ptr = [] (void* /*NULL*/, Args... args)
            {
                return (*FunPtr)(args...);
            };
            return delegate;
        }
        template <typename L>
        static inline function bind(L* object)
        {
            function delegate;
            delegate.m_this_ptr = object;
            delegate.m_stub_ptr = [] (void* instance, Args... args)
            {
                return (static_cast<L*>(instance)->operator()(args...));
            };
            return delegate;
        }
        template <typename T, Re_t (T::*Mem_fun_ptr) (Args...)>
        static inline function bind(T* object)
        {
            function delegate;
            delegate.m_this_ptr = object;
            delegate.m_stub_ptr = [] (void* instance, Args... args)
            {
                return (static_cast<T*>(instance)->*Mem_fun_ptr)(args...);
            };
            return delegate;
        }
        template <typename T, Re_t (T::*Mem_fun_ptr) (Args...) const>
        static inline function bind(T* object)
        {
            function delegate;
            delegate.m_this_ptr = object;
            delegate.m_stub_ptr = [] (void* instance, Args... args)
            {
                return (static_cast<const T*>(instance)->*Mem_fun_ptr)(args...);
            };
            return delegate;
        }
        Re_t operator() (Args... args) const
        {
            return (*m_stub_ptr)(m_this_ptr, args...);
        }
        operator delegate_key_t ( ) const
        {
            return { reinterpret_cast<std::uintptr_t>(m_this_ptr),
                     reinterpret_cast<std::uintptr_t>(m_stub_ptr) };
        }
    };

    Core::table_wrap<function> m_slots;

    template <typename T>
    void sfinae_con(delegate_key_t const& key, typename T::tracked* instance)
    {
        instance->tracked_connections.insert(key, this);
        tracked_connections.insert(key, instance);
    }
    template <typename T>
    void sfinae_dis(delegate_key_t const& key, typename T::tracked* instance)
    {
        instance->tracked_connections.remove(key);
        tracked_connections.remove(key);
    }

    template <typename T> void sfinae_con(...) { }
    template <typename T> void sfinae_dis(...) { }
    
    virtual void remove_tracked(delegate_key_t const& key)
    {
        tracked_connections.remove(key);
        m_slots.remove(key);
    }

    public:

    template <Re_t (*FunPtr)(Args...)>
    void connect()
    {
        auto delegate = function::template bind<FunPtr>();
        m_slots.insert(delegate, delegate);
    }
    template <typename L>
    void connect(L* instance)
    {
        auto delegate = function::template bind(instance);
        m_slots.insert(delegate, delegate);
    }
    template <typename T, Re_t(T::*Mem_fun_ptr)(Args...)>
    void connect(T* instance)
    {
        auto delegate = function::template bind<T, Mem_fun_ptr>(instance);
        m_slots.insert(delegate, delegate);
        sfinae_con<T>(delegate, instance);
    }
    template <typename T, Re_t(T::*Mem_fun_ptr)(Args...) const>
    void connect(T* instance)
    {
        auto delegate = function::template bind<T, Mem_fun_ptr>(instance);
        m_slots.insert(delegate, delegate);
        sfinae_con<T>(delegate, instance);
    }

    template <Re_t (*FunPtr)(Args... )>
    void disconnect()
    {
        auto delegate = function::template bind<FunPtr>();
        m_slots.remove(delegate);
    }
    template <typename L>
    void disconnect(L* instance)
    {
        auto delegate = function::template bind(instance);
        m_slots.remove(delegate);
    }
    template <typename T, Re_t(T::*Mem_fun_ptr)(Args...)>
    void disconnect(T* instance)
    {
        auto delegate = function::template bind<T, Mem_fun_ptr>(instance);
        m_slots.remove(delegate);
        sfinae_dis<T>(delegate, instance);
    }
    template <typename T, Re_t(T::*Mem_fun_ptr)(Args...) const>
    void disconnect(T* instance)
    {
        auto delegate = function::template bind<T, Mem_fun_ptr>(instance);
        m_slots.remove(delegate);
        sfinae_dis<T>(delegate, instance);
    }

    void operator() (Args... args) const
    {
        for (auto const& slot : m_slots)
        {
            slot.second(args...);
        }
    }
};

} // namespace Nano ------------------------------------------------------------

#endif // NANO_SIGNAL_SLOT_HPP
