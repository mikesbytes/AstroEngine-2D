/*
 * Named.cpp
 *
 *  Created on: May 1, 2013
 *      Author: Michael
 */

#include "Named.h"

Named::Named() {
	// TODO Auto-generated constructor stub

}

Named::~Named() {
	// TODO Auto-generated destructor stub
}

std::string Named::getName() {
	return nameString;
}

void Named::setName(const std::string& newName) {
	nameString = newName;
}
