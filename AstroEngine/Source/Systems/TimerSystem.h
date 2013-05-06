/*
 * TimerSystem.h
 *
 *  Created on: May 2, 2013
 *      Author: Michael
 */

#ifndef TIMERSYSTEM_H_
#define TIMERSYSTEM_H_

#include "../Nano/nano_signal_slot.hpp"
#include "System.h"

#include <map>
#include <SFML/Graphics.hpp>
#include <string>

struct Timer : public System {
	float elapsed;
	float delay;
	bool doesLoop;
	bool paused;
	Nano::signal<void()> trigger;
};

class TimerSystem {
public:
	TimerSystem();
	virtual ~TimerSystem();

	void update(const float& timeElapsed);
	Timer& addTimer(const float& delay, const std::string& name, bool doesLoop = false);
	Timer& getTimer(const std::string& name);

	std::map<std::string, Timer> timerMap;
};

#endif /* TIMERSYSTEM_H_ */
