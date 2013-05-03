/*
 * BasicMedium.cpp
 *
 *  Created on: May 1, 2013
 *      Author: Michael
 */

#include "BasicMedium.h"

BasicMedium::BasicMedium() {
	// TODO Auto-generated constructor stub
	setName("BasicMedium");
}

BasicMedium::~BasicMedium() {
	// TODO Auto-generated destructor stub
}

void BasicMedium::draw(const unsigned& layer, sf::RenderTarget& target, sf::RenderStates states) {
	for (auto i : drawables[layer]) {
		target.draw(*i.second, states);
	}
}

bool BasicMedium::addDrawable(const std::string& id,
		std::shared_ptr<sf::Drawable> newDrawable, unsigned layer) {
	if (drawables[layer].find(id) == drawables[layer].end()) {
		drawables[layer][id] = newDrawable;
		return true;
	}
	return false;
}

std::shared_ptr<sf::Drawable> BasicMedium::getDrawable(const std::string& id, unsigned layer) {
	if (drawables[layer].find(id) != drawables[layer].end()) {
		return drawables[layer][id];
	}
	return nullptr;
}

bool BasicMedium::removeDrawable(const std::string& id, unsigned layer) {
	if (drawables[layer].find(id) != drawables[layer].end()) {
		drawables[layer].erase(id);
	}
	return false;
}
