/*
 * System.h
 *
 *  Created on: May 9, 2013
 *      Author: Michael
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

//#include "../Managers/SceneManager/Scene.h"

#include <string>

namespace Managers {
	class Scene;
}

namespace Systems {

class System {
public:
	System();
	virtual ~System();

	virtual std::string name() const { return "System"; };
	virtual void load(){ }

	Managers::Scene* activeScene;
};

} /* namespace Systems */
#endif /* SYSTEM_H_ */
