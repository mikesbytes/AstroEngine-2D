/*
 * Scene.h
 *
 *  Created on: May 6, 2013
 *      Author: Michael
 */

#ifndef SCENE_H_
#define SCENE_H_

#include "../../Graphics/Window.h"
#include "../../Graphics/SceneGraph.h"
#include "../../Systems/System.h"

//systems
#include "../../Systems/InputSystem.h"

#include <memory>
#include <map>
#include <string>

namespace Managers {
class Scene {
public:
	Scene();
	virtual ~Scene();

	void processInput(sf::Event& event);
	void draw(sf::RenderTarget& target);

	void addSystem(Systems::System* newSystem);
	Systems::System* getSystem(const std::string& systemName);

	Graphics::Layer sceneLayer;
	sf::Transform baseTransform;
	std::map<std::string, Systems::System*> systems;

protected:

	Systems::InputSystem* inputSystem;

};
} /* namespace Managers */

#endif /* SCENE_H_ */
