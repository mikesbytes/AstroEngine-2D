/*
 * Main.cpp
 *
 *  Created on: Apr 25, 2013
 *      Author: Michael
 */

#include <iostream>
#include <memory>
#include "SFML/Graphics.hpp"
#include "Graphics/Window.h"
#include "Graphics/Canvas.h"
#include "Graphics/Mediums/TileMedium.h"
#include "Graphics/Mediums/BasicMedium.h"
#include "Systems/TimerSystem.h"

int main() {
	Window w;
	TimerSystem ts;
	auto c = std::make_shared<Canvas>();
	c->setPosition(0,0);
	c->setScale(.5, .5);

	auto tm = std::make_shared<TileMedium>();
	c->mediums.push_back(tm);

	auto bm = std::make_shared<BasicMedium>();
	c->mediums.push_back(bm);

	auto r = std::make_shared<sf::RectangleShape>();
	r->setSize(sf::Vector2f(100,100));
	r->setFillColor(sf::Color::Red);

	bm->addDrawable("rect", r);

	const int level[] =
	{
			1,2,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,
			2,2,2,2,2,2,2,2,
			1,1,1,1,1,1,1,1
	};

	if (tm->load("Data/Media/Tileset.png", sf::Vector2u(128, 128), level, 8, 4))
		std::cout << "tiles loaded";
	else std::cout << "tiles not loaded";
	std::flush(std::cout);
	w.activeCanvas = c;

	//w.graphicsLoop.onLoop.connect<TimerSystem, &TimerSystem::update>(&ts);
	//ts.addTimer(5, "closeTimer").trigger.connect<Window, &Window::close>(&w);
	w.onClosed.connect<Window, &Window::close>(&w);
	w.open();
}
