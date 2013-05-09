/*
 * Main.cpp
 *
 *  Created on: Apr 25, 2013
 *      Author: Michael
 */

#include <iostream>
#include <memory>
#include "SFML/Graphics.hpp"
#include "Graphics/SceneGraph.h"
#include "Graphics/Rectangle.h"
#include "Graphics/Window.h"
#include "Graphics/TileView.h"

int main() {
	auto l = std::make_shared<Graphics::Layer>();
	auto t = new Graphics::TileView;
	auto r = new Graphics::Rectangle;
	r->rect.setSize(sf::Vector2f(50,50));
	r->rect.setFillColor(sf::Color::Red);

	t->tileSheet.setTileSize(sf::Vector2u(128,128));
	if (t->tileSheet.tileSheetTex.loadFromFile("Data/Media/Tileset.png")) {
		std::cout << "Tileset loaded";
	}
	t->tileSheet.tileSheetTex.setSmooth(true);

	std::vector<unsigned> mapVec {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};

	t->setTileSize(sf::Vector2f(64,64));
	t->loadMap(mapVec, 21, 5);
	l->addChild(t);
	l->addChild(r);

	Graphics::Window w;

	w.activeNode = l;
	w.onClosed.connect<Graphics::Window, &Graphics::Window::close>(&w);

	w.open();
}
