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
	inputSystem = new Systems::InputSystem;
	addSystem(inputSystem);
}

Scene::~Scene() {
	// TODO Auto-generated destructor stub
}

void Scene::processInput(sf::Event& event) {
	inputSystem->proccessInput(event);
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
