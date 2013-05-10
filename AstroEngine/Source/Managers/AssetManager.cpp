/*
 * AssetManager.cpp
 *
 *  Created on: May 9, 2013
 *      Author: Michael
 */

#include "AssetManager.h"

namespace Managers {

AssetManager::AssetManager() {
	// TODO Auto-generated constructor stub

}

AssetManager::~AssetManager() {
	// TODO Auto-generated destructor stub
}

std::string AssetManager::parseFileName(const std::string& fileName) {
	// TODO asset filename parsing (so you can have file overloads)
	return fileName;
}

void AssetManager::registerAssetType(Assets::AssetInterface* newType) {
	assetTypes[newType->name()] = newType;
}

} /* namespace Managers */
