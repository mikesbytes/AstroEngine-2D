/*
 * SceneManager.cpp
 *
 *  Created on: May 6, 2013
 *      Author: Michael
 */

#include "SceneManager.h"

SceneManager::SceneManager() {
	// TODO Auto-generated constructor stub

}

SceneManager::~SceneManager() {
	// TODO Auto-generated destructor stub
}

std::shared_ptr<Scene> SceneManager::newScene(const std::string& sceneName) {
	auto newScene = std::make_shared<Scene>();
	sceneMap[sceneName] = newScene;
	return newScene;
}

bool SceneManager::changeScene(std::shared_ptr<Scene>& nextScene) {
	if (nextScene) {
		activeScene = nextScene;
		//linkedWindow->activeCanvas = nextScene->sceneCanvas;
		return true;
	}
	return false;
}

bool SceneManager::changeScene(const std::string& nextSceneName) {
	if (sceneMap.find(nextSceneName) != sceneMap.end()) { //the scene exists
		return changeScene(sceneMap[nextSceneName]);
	}

	return false;
}
