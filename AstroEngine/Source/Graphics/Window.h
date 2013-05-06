/*
 * Window.h
 *
 *  Created on: May 2, 2013
 *      Author: Michael
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <SFML/Graphics.hpp>
#include "../Utility/Loop.h"
#include "../Nano/nano_signal_slot.hpp"
#include "Canvas.h"
#include <memory>

class Window {
public:
	Window();
	virtual ~Window();

	void open();
	void close();
	void reset();
	void frame(const float& dTime);

	void setTitle(const std::string newTitle);
	void setResolution(const float& sizeX, const float& sizeY);

	sf::RenderWindow window;
	Loop graphicsLoop;

	std::shared_ptr<Canvas> activeCanvas;

	//signals
	Nano::signal<void()> onClosed;
protected:
	sf::Vector2i resolution;
	std::string title;
};

#endif /* WINDOW_H_ */
