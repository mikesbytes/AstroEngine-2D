/*
 * Main.cpp
 *
 *  Created on: Apr 25, 2013
 *      Author: Michael
 */

#include <iostream>
#include <memory>
#include "SFML/Graphics.hpp"
#include "Managers/SceneManager.h"
#include "Managers/AssetManager.h"
#include "Assets/Texture.h"
#include "Graphics/SceneGraph.h"
#include "Graphics/Rectangle.h"
#include "Graphics/Sprite.h"
#include "Graphics/Window.h"
#include "Graphics/TileView.h"

int main() {
	auto w = std::make_shared<Graphics::Window>();
	Managers::SceneManager sm;
	sm.linkedWindow = w;
	auto s = sm.newScene("TestScene");
	sm.changeScene(s);

	Managers::AssetManager am;
	am.registerAssetType(new Assets::Texture);

	auto r = new Graphics::Rectangle;
	r->rect.setSize(sf::Vector2f(50,50));
	r->rect.setFillColor(sf::Color::Red);

	auto spr = new Graphics::Sprite;
	spr->setTexture(am.loadAsset<sf::Texture>("Texture", "Data/Media/test.png"));

	s->sceneLayer.addChild(r);
	s->sceneLayer.addChild(spr);

	auto is = dynamic_cast<Systems::InputSystem*>(s->getSystem("InputSystem"));
	is->keySignal(sf::Keyboard::Escape, false)
			.connect<Graphics::Window, &Graphics::Window::close>(&*w);

	w->open();
}
