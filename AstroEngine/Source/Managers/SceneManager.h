/*
 * SceneManager.h
 *
 *  Created on: May 6, 2013
 *      Author: Michael
 */

#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "../Graphics/Window.h"
#include "SceneManager/Scene.h"

#include <memory>
#include <string>
#include <map>

class SceneManager {
public:
	SceneManager();
	virtual ~SceneManager();

	std::shared_ptr<Scene> newScene(const std::string& sceneName);
	bool changeScene(std::shared_ptr<Scene>& nextScene);
	bool changeScene(const std::string& nextSceneName);

	std::shared_ptr<Graphics::Window> linkedWindow;
	std::shared_ptr<Scene> activeScene;
	std::map<std::string, std::shared_ptr<Scene> > sceneMap;
};

#endif /* SCENEMANAGER_H_ */
