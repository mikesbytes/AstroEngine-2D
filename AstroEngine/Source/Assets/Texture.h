/*
 * Texture.h
 *
 *  Created on: May 9, 2013
 *      Author: Michael
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "Asset.h"

#include <SFML/Graphics.hpp>

namespace Assets {

class Texture : public Asset<sf::Texture> {
public:
	Texture();
	virtual ~Texture();
	virtual std::string name() const { return "Texture"; }

	virtual sf::Texture* load(const std::string& fileName);

protected:
	bool smooth;
};

} /* namespace Assets */
#endif /* TEXTURE_H_ */
