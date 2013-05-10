/*
 * Sprite.h
 *
 *  Created on: May 9, 2013
 *      Author: Michael
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "SceneGraph.h"

#include <SFML/Graphics.hpp>

namespace Graphics {

class Sprite : public Node {
public:
	Sprite();
	virtual ~Sprite();

	void setTexture(sf::Texture* texture); //set sprite texture
	void setPosition(const sf::Vector2f& newPos); //set position

protected:

	virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const;

	sf::Sprite sprite;
};

} /* namespace Graphics */
#endif /* SPRITE_H_ */
