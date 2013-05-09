/*
 * SceneGraph.cpp
 *
 *  Created on: May 6, 2013
 *      Author: Michael
 */

#include "SceneGraph.h"

#include <algorithm>

namespace Graphics {

Node::Node() {

}

Node::~Node() {

}

bool Node::addChild(Node* child_) {
	std::vector<Node*>::iterator it;
	it = std::find (children.begin(), children.end(), child_);
	if (it == children.end()) {
		children.push_back(child_);
		return true;
	}
	return false;
}

bool Node::removeChild(Node* child_) {
	std::vector<Node*>::iterator it;
	it = std::find (children.begin(), children.end(), child_);
	if (it != children.end()) {
		children.erase(it);
		return true;
	}
	return false;
}

Node* Node::childAt(unsigned index) {
	return children.at(index);
}

void Node::clearChildren() {
	for (unsigned i = 0; i < children.size(); i++) {
		delete children[i];
	}
}

void Node::draw(sf::RenderTarget& target,
		const sf::Transform& parentTransform) const {
	sf::Transform combinedTransform = parentTransform * thisTransform;

	onDraw(target, combinedTransform);

	for (auto i : children) {
		i->draw(target, combinedTransform);
	}
}

Layer::Layer() {
}

Layer::~Layer() {
}

void Layer::onDraw(sf::RenderTarget& target,
		const sf::Transform& transform) const {
}

} /* namespace Graphics */
