/*
 * Asset.h
 *
 *  Created on: May 9, 2013
 *      Author: Michael
 *
 *  Derive from this class to add a new asset type
 *  Assets are loaded by a string. There is a special indexing
 *  feature that allows what is essentially "file overloading"
 *  so people can easily create mods.
 */

#ifndef ASSET_H_
#define ASSET_H_

#include <string>
#include <map>

namespace Assets {

class AssetInterface {
public:
	virtual ~AssetInterface() {}

	virtual std::string name() const { return "Asset"; }
};

template <typename T>
class Asset : public AssetInterface {
public:
	Asset() {};
	virtual ~Asset() {};

	//called by AssetManager to load assets
	virtual T* load (const std::string& fileName) = 0;

protected:
	std::map<std::string, T*> objects; //load objects into here
};

} /* namespace Assets */
#endif /* ASSET_H_ */
