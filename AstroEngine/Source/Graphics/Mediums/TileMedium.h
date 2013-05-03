/*
 * TileMedium.h
 *
 *  Created on: May 2, 2013
 *      Author: Michael
 */

#ifndef TILEMEDIUM_H_
#define TILEMEDIUM_H_

#include "../Medium.h"
#include <SFML/Graphics.hpp>

class TileMedium : public Medium {
public:
	TileMedium();
	virtual ~TileMedium();

	virtual void draw(const unsigned& layer, sf::RenderTarget& target, sf::RenderStates states);

	bool load (const std::string& tileSet, sf::Vector2u tileSize, const int* tiles,
			unsigned int width, unsigned int height);

protected:
	sf::VertexArray verts;
	sf::Texture tileSetTex;

};

#endif /* TILEMEDIUM_H_ */
