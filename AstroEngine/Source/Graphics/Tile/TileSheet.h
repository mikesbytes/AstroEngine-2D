/*
 * TileMap.h
 *
 *  Created on: May 7, 2013
 *      Author: Michael
 *
 *  Class for tilesheet management
 *
 *  TODO: Implement features for tile stitching and dynamic loading
 *
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_

#include <SFML/Graphics.hpp>

namespace Graphics {

class TileSheet {
public:
	TileSheet();
	virtual ~TileSheet();

	void setTileSize(const sf::Vector2u& newSize); //resize tile size
	void setSheetSize(const sf::Vector2u& newSize); //resize tilesheet

	//void setTexCoords(sf::Vertex& quad[], const unsigned & tileIndex); //set tex coords of quad

	sf::Texture tileSheetTex; //texture for tilesheet
	sf::Vector2u tileSize;

protected:
	sf::Vector2u sheetSize;
};

} /* namespace Graphics */
#endif /* TILEMAP_H_ */
