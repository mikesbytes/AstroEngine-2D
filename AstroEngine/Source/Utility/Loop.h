/*
 * Loop.h
 *
 *  Created on: May 2, 2013
 *      Author: Michael
 */

#ifndef LOOP_H_
#define LOOP_H_

#include <SFML/Graphics.hpp>
#include "../Nano/nano_signal_slot.hpp"

class Loop {
public:
	Loop();
	virtual ~Loop();

	void start();
	void loop();
	void stop();

	float getDelay() const {
		return delay;
	}

	void setDelay(float delay) {
		this->delay = delay;
	}

	Nano::signal<void(const float&)> onLoop;

protected:
	bool looping;
	float delay;
	sf::Clock loopClock;
};

#endif /* LOOP_H_ */
