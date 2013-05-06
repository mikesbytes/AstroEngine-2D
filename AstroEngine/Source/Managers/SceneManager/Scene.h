/*
 * Scene.h
 *
 *  Created on: May 6, 2013
 *      Author: Michael
 */

#ifndef SCENE_H_
#define SCENE_H_

#include "../../Graphics/Canvas.h"
#include <memory>

class Scene {
public:
	Scene();
	virtual ~Scene();

	std::shared_ptr<Canvas> sceneCanvas;
};

#endif /* SCENE_H_ */
