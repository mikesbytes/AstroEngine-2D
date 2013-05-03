/*
 * Loop.cpp
 *
 *  Created on: May 2, 2013
 *      Author: Michael
 */

#include "Loop.h"

Loop::Loop() {
	// TODO Auto-generated constructor stub
	looping = false;
	delay = 0;
}

Loop::~Loop() {
	// TODO Auto-generated destructor stub
}

void Loop::start() {
	looping = true;
	loopClock.restart();
	loop();
}

void Loop::loop() {
	while (looping) {
		if (delay != 0) { //if there is a delay, otherwise max speed
			while (loopClock.getElapsedTime().asSeconds() <= delay) {} //stop until the delay has passed
		}
		onLoop(loopClock.restart().asSeconds());
	}
}

void Loop::stop() {
	looping = false;
}
