/*
 * TileView.cpp
 *
 *  Created on: May 7, 2013
 *      Author: Michael
 */

#include "TileView.h"

namespace Graphics {

TileView::TileView() {
	// TODO Auto-generated constructor stub
	//states.texture = &tileSheet.tileSheetTex;
}

TileView::~TileView() {
	// TODO Auto-generated destructor stub
}

bool TileView::loadMap(
		const std::vector<unsigned>& map, const unsigned& width,
		const unsigned& height) {
	verts.setPrimitiveType(sf::Quads);

	//resize vertex array to fit the map
	verts.resize(width * height * 4);

	for (unsigned i = 0; i < width; i++) {
		for (unsigned j = 0; j < height; j++) {

			//get number of current tile
			int tileNumber = map[i + j * width];

			//get current quad
			sf::Vertex* quad = &verts[(i + j * width) * 4];

			//set quad coordinates
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			//set texture coordinates
			int tv = tileNumber / (tileSheet.tileSheetTex.getSize().x /
					tileSheet.tileSize.x);
			int tu = tileNumber % (tileSheet.tileSheetTex.getSize().x /
					tileSheet.tileSize.x);

			quad[0].texCoords = sf::Vector2f(tu * tileSheet.tileSize.x, tv * tileSheet.tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSheet.tileSize.x, tv * tileSheet.tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSheet.tileSize.x, (tv + 1) * tileSheet.tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSheet.tileSize.x, (tv + 1) * tileSheet.tileSize.y);
		}
	}

	return true;
}

void TileView::onDraw(sf::RenderTarget& target,
		const sf::Transform& transform) const {
	sf::RenderStates states;
	states.transform *= transform; //add the transformation
	states.texture = &tileSheet.tileSheetTex; //set the texture
	target.draw(verts, states); //draw it
}

} /* namespace Graphics */
