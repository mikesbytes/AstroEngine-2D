/*
 * Window.cpp
 *
 *  Created on: May 2, 2013
 *      Author: Michael
 */

#include "Window.h"

namespace Graphics {
Window::Window() {
	// TODO Auto-generated constructor stub
	resolution.x = 800;
	resolution.y = 600;
	title = "Window";
	graphicsLoop.onLoop.connect<Window, &Window::frame>(this); //connect frame to loop
}

Window::~Window() {
	// TODO Auto-generated destructor stub
}

void Window::open() {
	window.create(sf::VideoMode(resolution.x, resolution.y), title);
	window.setVerticalSyncEnabled(true);
	graphicsLoop.start();
}

void Window::close() {
	graphicsLoop.stop();
	window.close();
}

void Window::reset() {
	window.create(sf::VideoMode(resolution.x, resolution.y), title);
}

void Window::setTitle(const std::string newTitle) {
	title = newTitle;
}

void Window::frame(const float& dTime) {
	window.clear();

	//get input
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed: //x button clicked
			onClosed();
			break;
		default:
			break;
		}
	}

	activeNode->draw(window, baseTransform); //draw active node

	window.display();
}

void Window::setResolution(const float& sizeX, const float& sizeY) {
	resolution.x = sizeX;
	resolution.y = sizeY;
}
} /* namespace Graphics */
