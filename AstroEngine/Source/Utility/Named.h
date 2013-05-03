/*
 * Named.h
 *
 *  Created on: May 1, 2013
 *      Author: Michael
 */

#ifndef NAMED_H_
#define NAMED_H_

#include <string>

class Named {
public:
	Named();
	virtual ~Named();

	std::string getName();
	void setName(const std::string& newName);

protected:
	std::string nameString;
};

#endif /* NAMED_H_ */
