/*
 * SceneGraph.h
 *
 *  Created on: May 6, 2013
 *      Author: Michael
 *
 * 	Anything that you see is based off of this.
 */

#ifndef SCENEGRAPH_H_
#define SCENEGRAPH_H_

#include <vector>
#include <SFML/Graphics.hpp>

namespace Graphics {

class Node {
public:
	Node();
	virtual ~Node();

	bool addChild(Node* child_); //add a child
	bool removeChild(Node* child_); //remove a child
	Node* childAt(unsigned index); //get child at index
	void clearChildren(); //remove all children

	//general draw function
	virtual void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const;

private:

	//GO DRAW YOURSELF
	virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;

	sf::Transform thisTransform;
	std::vector<Node*> children;
};


//General purpose layer class. Nothing special
class Layer : public Node {
public:
	Layer();
	virtual ~Layer();

private:
	virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const;
};

} /* namespace Graphics */
#endif /* SCENEGRAPH_H_ */
