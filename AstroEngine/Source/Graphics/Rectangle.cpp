/*
 * Rectangle.cpp
 *
 *  Created on: May 7, 2013
 *      Author: Michael
 */

#include "Rectangle.h"

namespace Graphics {

Rectangle::Rectangle() {
	// TODO Auto-generated constructor stub

}

Rectangle::~Rectangle() {
	// TODO Auto-generated destructor stub
}

void Rectangle::onDraw(sf::RenderTarget& target,
		const sf::Transform& transform) const {
	target.draw(rect, transform);
}

} /* namespace Graphics */
