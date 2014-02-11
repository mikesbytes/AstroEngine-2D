/*
 * Scene.cpp
 *
 *  Created on: May 6, 2013
 *      Author: Michael
 */

#include "Scene.h"


namespace Managers {
Scene::Scene() {
	// setup default systems
	//inputSystem = new Systems::InputSystem;

	// add input system
	addSystem(new Systems::InputSystem);
}

Scene::~Scene() {
	// TODO Auto-generated destructor stub
}

void Scene::processInput(sf::Event& event) {
	//inputSystem->proccessInput(event);
	dynamic_cast<Systems::InputSystem *>(getSystem("InputSystem"))->processInput(event);
}

void Scene::draw(sf::RenderTarget& target) {
	sceneLayer.draw(target, baseTransform);
}

void Scene::addSystem(Systems::System* newSystem) {
	systems[newSystem->name()] = newSystem;
	newSystem->activeScene = this;
	newSystem->load();
}

Systems::System* Scene::getSystem(const std::string& systemName) {
	return systems[systemName];
}

} /* namespace Managers */
