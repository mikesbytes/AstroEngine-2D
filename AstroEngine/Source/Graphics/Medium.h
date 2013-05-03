/*
 * Medium.h
 *
 *  Created on: May 1, 2013
 *      Author: Michael
 */

#ifndef MEDIUM_H_
#define MEDIUM_H_


#include "../Utility/Named.h"
#include <SFML/Graphics.hpp>

class Medium : public Named{
public:
	Medium();
	virtual ~Medium();

	virtual void draw(const unsigned& layer, sf::RenderTarget& target, sf::RenderStates states) = 0;
};

#endif /* MEDIUM_H_ */
