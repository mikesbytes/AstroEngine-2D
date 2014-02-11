/*
 * InputSystem.cpp
 *
 *  Created on: May 9, 2013
 *      Author: Michael
 */

#include "InputSystem.h"

namespace Systems {

InputSystem::InputSystem() {
	// TODO Auto-generated constructor stub

}

InputSystem::~InputSystem() {
	// TODO Auto-generated destructor stub
}

void InputSystem::processInput(sf::Event& event) {
	switch (event.type) {
	case sf::Event::KeyPressed:
		keyPressedSignals[event.key.code]();
		break;
	case sf::Event::KeyReleased:
		keyReleasedSignals[event.key.code]();
		break;
	default:
		break;
	}
}

bool InputSystem::isKeyPressed(const sf::Keyboard::Key& keyCode) {
	return sf::Keyboard::isKeyPressed(keyCode);
}

Nano::signal<void()>& InputSystem::keySignal(const sf::Keyboard::Key& keyCode,
		bool released) {

	if (released) { //is it a release or press code?
		return keyReleasedSignals[keyCode]; //return reference to signal
	} else {
		return keyPressedSignals[keyCode];
	}
}

} /* namespace Systems */
