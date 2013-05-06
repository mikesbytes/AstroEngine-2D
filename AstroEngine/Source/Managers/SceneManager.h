/*
 * SceneManager.h
 *
 *  Created on: May 6, 2013
 *      Author: Michael
 */

#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include <memory>
#include "../Graphics/Window.h"

class SceneManager {
public:
	SceneManager();
	virtual ~SceneManager();

	std::shared_ptr<Window> linkedWindow;
};

#endif /* SCENEMANAGER_H_ */
