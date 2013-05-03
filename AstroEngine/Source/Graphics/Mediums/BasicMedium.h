/*
 * BasicMedium.h
 *
 *  Created on: May 1, 2013
 *      Author: Michael
 */

#ifndef BASICMEDIUM_H_
#define BASICMEDIUM_H_

#include "../Medium.h"
#include <map>
#include <unordered_map>
#include <memory>

class BasicMedium: public Medium {
public:
	BasicMedium();
	virtual ~BasicMedium();

	virtual void draw(const unsigned& layer, sf::RenderTarget& target, sf::RenderStates states);
	bool addDrawable(const std::string& id, std::shared_ptr<sf::Drawable> newDrawable,
			unsigned layer = 0);
	std::shared_ptr<sf::Drawable> getDrawable(const std::string& id, unsigned layer = 0);
	bool removeDrawable(const std::string& id, unsigned layer = 0);

	std::map<unsigned, std::unordered_map<std::string, std::shared_ptr<sf::Drawable> > > drawables;
};

#endif /* BASICMEDIUM_H_ */
