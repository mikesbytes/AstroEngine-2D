/*
 * AssetManager.h
 *
 *  Created on: May 9, 2013
 *      Author: Michael
 *
 *  Asset management class
 *  To create a new asset type, create a class deriving from Assets::Asset
 *
 */

#ifndef ASSETMANAGER_H_
#define ASSETMANAGER_H_

#include "../Assets/Asset.h"
#include "Manager.h"

#include <map>

namespace Managers {

class AssetManager : public Manager {
public:
	AssetManager();
	virtual ~AssetManager();

	template <typename T>
	T* loadAsset(const std::string& assetType, const std::string& fileName) {
		//downcast the appropriate getter
		auto assetGetter = dynamic_cast<Assets::Asset<T>*>(assetTypes.at(assetType));
		return assetGetter->load(parseFileName(fileName));
	}

	std::string parseFileName(const std::string& fileName);
	void registerAssetType(Assets::AssetInterface* newType);

	std::map <std::string, Assets::AssetInterface*> assetTypes;
};

} /* namespace Managers */
#endif /* ASSETMANAGER_H_ */
