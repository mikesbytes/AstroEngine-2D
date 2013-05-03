/*
 * Canvas.cpp
 *
 *  Created on: May 1, 2013
 *      Author: Michael
 */

#include "Canvas.h"

Canvas::Canvas() {
	// TODO Auto-generated constructor stub
	layerCount = 0;
	setName("Canvas");
}

Canvas::~Canvas() {
	// TODO Auto-generated destructor stub
}

void Canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	states.transform *= getTransform();
	for (unsigned i = 0; i <= layerCount; i++) {
		for (auto j : mediums) {
			j->draw(i, target, states);
		}
	}
}
