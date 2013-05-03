/*
 * TimerSystem.cpp
 *
 *  Created on: May 2, 2013
 *      Author: Michael
 */

#include "TimerSystem.h"
#include <iostream>

TimerSystem::TimerSystem() {
	// TODO Auto-generated constructor stub

}

TimerSystem::~TimerSystem() {
	// TODO Auto-generated destructor stub
}

void TimerSystem::update(const float& timeElapsed) {
	for (auto i = timerMap.begin(); i != timerMap.end(); i++) {
		if (!i->second.paused) {
			i->second.elapsed += timeElapsed;
			if (i->second.elapsed >= i->second.delay) {
				i->second.trigger();
				if (i->second.doesLoop) {
					i->second.elapsed = 0;
				} else {
					timerMap.erase(i);
				}
			}
		}
	}
}

Timer& TimerSystem::addTimer(const float& delay, const std::string& name,
		bool doesLoop) {
	Timer newTimer;
	newTimer.delay = delay;
	newTimer.paused = false;
	newTimer.elapsed = 0;

	timerMap[name] = newTimer;
	std::cout << "added timer: " << name << std::endl;
	return timerMap[name];
}

Timer& TimerSystem::getTimer(const std::string& name) {
	return timerMap[name];
}
