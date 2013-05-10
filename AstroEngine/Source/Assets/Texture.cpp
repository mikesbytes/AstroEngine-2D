/*
 * Texture.cpp
 *
 *  Created on: May 9, 2013
 *      Author: Michael
 */

#include "Texture.h"

namespace Assets {

Texture::Texture() {
	// TODO Auto-generated constructor stub
	smooth = true;
}

Texture::~Texture() {
	// TODO Auto-generated destructor stub
}

sf::Texture* Texture::load(const std::string& fileName) {
	if (objects.find(fileName) != objects.end()) { //if texture has already been loaded
		return objects[fileName];
	}

	//load new texture
	auto newTex = new sf::Texture;
	newTex->loadFromFile(fileName);
	objects[fileName] = newTex;

	//set attributes
	newTex->setSmooth(smooth);

	return newTex;
}

} /* namespace Assets */
