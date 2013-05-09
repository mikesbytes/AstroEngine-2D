/*
 * TileSheet.cpp
 *
 *  Created on: May 7, 2013
 *      Author: Michael
 */

#include "TileSheet.h"

namespace Graphics {

TileSheet::TileSheet() {
	// TODO Auto-generated constructor stub

}

TileSheet::~TileSheet() {
	// TODO Auto-generated destructor stub
}

void TileSheet::setTileSize(const sf::Vector2u& newSize) {
	tileSize = newSize;
}

void TileSheet::setSheetSize(const sf::Vector2u& newSize) {
	sheetSize = newSize;
}

/*
void TileSheet::setTexCoords(sf::Vertex& quad[], const unsigned & tileIndex) {
	int tu = tileIndex % (tileSheetTex.getSize().y / tileSize.y);
	int tv = tileIndex / (tileSheetTex.getSize().x / tileSize.x);

	quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
	quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
	quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
	quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
}
*/

} /* namespace Graphics */
