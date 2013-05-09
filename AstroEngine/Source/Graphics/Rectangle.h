/*
 * Rectangle.h
 *
 *  Created on: May 7, 2013
 *      Author: Michael
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "SceneGraph.h"

#include <SFML/Graphics.hpp>

namespace Graphics {

class Rectangle : public Node {
public:
	Rectangle();
	virtual ~Rectangle();

	virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const;

	sf::RectangleShape rect;
};

} /* namespace Graphics */
#endif /* RECTANGLE_H_ */
