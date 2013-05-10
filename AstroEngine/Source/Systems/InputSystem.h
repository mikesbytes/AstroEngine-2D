/*
 * InputSystem.h
 *
 *  Created on: May 9, 2013
 *      Author: Michael
 */

#ifndef INPUTSYSTEM_H_
#define INPUTSYSTEM_H_

#include "System.h"
#include "../Nano/nano_signal_slot.hpp"

#include <SFML/Graphics.hpp>
#include <map>

namespace Systems {

class InputSystem : public System{
public:
	InputSystem();
	virtual ~InputSystem();
	virtual std::string name() const { return "InputSystem"; }

	//put input here
	void proccessInput(sf::Event& event);

	//is a keyboard key pressed
	bool isKeyPressed(const sf::Keyboard::Key& keyCode);
	//get a signal for a key press or release
	Nano::signal<void()>& keySignal(const sf::Keyboard::Key& keyCode, bool released = false);

protected:
	std::map<sf::Keyboard::Key, Nano::signal<void()> > keyReleasedSignals;
	std::map<sf::Keyboard::Key, Nano::signal<void()> > keyPressedSignals;
};

} /* namespace Systems */
#endif /* INPUTSYSTEM_H_ */
