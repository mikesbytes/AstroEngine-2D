/*
 * TileMedium.cpp
 *
 *  Created on: May 2, 2013
 *      Author: Michael
 */

#include "TileMedium.h"
#include <iostream>

TileMedium::TileMedium() {
	// TODO Auto-generated constructor stub
	setName("TileMedium");
}

TileMedium::~TileMedium() {
	// TODO Auto-generated destructor stub
}

void TileMedium::draw(const unsigned& layer, sf::RenderTarget& target, sf::RenderStates states) {
	// TODO Tile layers

		states.texture = &tileSetTex;
		target.draw(verts, states);

}

bool TileMedium::load(const std::string& tileSet, sf::Vector2u tileSize,
		const int* tiles, unsigned int width, unsigned int height) {
	//load tileset
	if (!tileSetTex.loadFromFile(tileSet))
		return false;

	tileSetTex.setSmooth(true);

	//resize vertex array to fit level size
	verts.setPrimitiveType(sf::Quads);
	verts.resize(width * height * 4);

	for (unsigned i = 0; i < width; i++) {
		for (unsigned int j = 0; j < height; j++) {
			//current tile number
			int tileNumber = tiles[i + j * width];

			//find position in tileset
			int tv = tileNumber / (tileSetTex.getSize().x / tileSize.y);
			int tu = tileNumber % (tileSetTex.getSize().y / tileSize.y);

			//pointer to current quad
			sf::Vertex* quad = &verts[(i + j * width) * 4];

			//define 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			//define texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	}

	return true;
}
