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
#include "../Managers/SceneManager/Scene.h"
#include "../Nano/nano_signal_slot.hpp"
#include "SceneGraph.h"
#include <memory>

namespace Managers { class Scene; }

namespace Graphics {
class Window {
public:
	Window();
	virtual ~Window();

	void open(); //open window
	void close(); //close window
	void reset(); //reset window
	void frame(const float& dTime); //frame function (with delta time)

	void setTitle(const std::string newTitle); //set window title
	void setResolution(const float& sizeX, const float& sizeY); //set window resolution

	sf::RenderWindow window; //the window
	Utility::Loop graphicsLoop; //the loop

	std::shared_ptr<Managers::Scene> activeScene; //Node to draw


	//signals
	Nano::signal<void()> onClosed;

protected:
	sf::Vector2i resolution;
	std::string title;
	sf::Transform baseTransform;
};
} /* namespace Graphics */

#endif /* WINDOW_H_ */
