/*
 * Canvas.h
 *
 *  Created on: May 1, 2013
 *      Author: Michael
 *
 *	Canvas is used to draw things
 *  You can add mediums to a canvas
 */

#ifndef CANVAS_H_
#define CANVAS_H_

#include "Medium.h"
#include "../Utility/Named.h"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Canvas : public Named, public sf::Drawable, public sf::Transformable{
public:
	Canvas();
	virtual ~Canvas();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	unsigned int layerCount; //layer count
	std::vector<std::shared_ptr<Medium> > mediums;
};

#endif /* CANVAS_H_ */
