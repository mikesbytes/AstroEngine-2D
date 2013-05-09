/*
 * TileView.h
 *
 *  Created on: May 7, 2013
 *      Author: Michael
 *
 *  Class for containing and drawing tilemaps
 */

#ifndef TILEVIEW_H_
#define TILEVIEW_H_

#include "SceneGraph.h"
#include "Tile/TileSheet.h"

#include <vector>

namespace Graphics {

class TileView : public Node {
public:
	TileView();
	virtual ~TileView();

	//load map from vector of unsigned ints
	bool loadMap(const std::vector<unsigned>& map, const unsigned& width,
			const unsigned& height);

	//get tile size (in px)
	sf::Vector2f getTileSize() const {
		return tileSize;
	}

	//set tile size (in px)
	void setTileSize(sf::Vector2f tileSize) {
		this->tileSize = tileSize;
	}

	sf::VertexArray verts;
	TileSheet tileSheet;

private:
	virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const;

	sf::Vector2f tileSize;
};

} /* namespace Graphics */
#endif /* TILEVIEW_H_ */
