/*
 * Sprite.cpp
 *
 *  Created on: May 9, 2013
 *      Author: Michael
 */

#include "Sprite.h"

namespace Graphics {

Sprite::Sprite() {
	// TODO Auto-generated constructor stub

}

Sprite::~Sprite() {
	// TODO Auto-generated destructor stub
}

void Sprite::setTexture(sf::Texture* texture) {
	sprite.setTexture(*texture);
}

void Sprite::setPosition(const sf::Vector2f& newPos) {
	sprite.setPosition(newPos);
}

void Sprite::onDraw(sf::RenderTarget& target,
		const sf::Transform& transform) const {
	target.draw(sprite, transform);
}

} /* namespace Graphics */
