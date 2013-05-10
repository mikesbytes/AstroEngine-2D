/*
 * Window.cpp
 *
 *  Created on: May 2, 2013
 *      Author: Michael
 */

#include "Window.h"

namespace Graphics {
Window::Window() {
	resolution.x = 800;
	resolution.y = 600;
	title = "Window";
	graphicsLoop.onLoop.connect<Window, &Window::frame>(this); //connect frame to loop
}

Window::~Window() {
	// TODO Auto-generated destructor stub
}

void Window::open() {
	window.create(sf::VideoMode(resolution.x, resolution.y), title); //start window
	window.setVerticalSyncEnabled(true); //vsync
	graphicsLoop.start();
}

void Window::close() {
	graphicsLoop.stop(); //stop loop
	window.close(); //close window
}

void Window::reset() {
	window.create(sf::VideoMode(resolution.x, resolution.y), title); //recreate window
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
			activeScene->processInput(event);
			break;
		}
	}

	activeScene->draw(window); //draw active node

	window.display();
}

void Window::setResolution(const float& sizeX, const float& sizeY) {
	resolution.x = sizeX;
	resolution.y = sizeY;
}
} /* namespace Graphics */
