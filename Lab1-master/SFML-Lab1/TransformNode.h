#ifndef _TRANSFORM_NODE_H_
#define _TRANSFORM_NODE_H_

#include <vector>
using std::vector;

#include <SFML/Graphics.hpp>

class TransformNode {
public:
	TransformNode(sf::Shape *shape);
	

	bool addChild(TransformNode *child);
	bool removeChild(TransformNode *child);
	bool hasChild(TransformNode *child);

	void draw(sf::RenderTarget *target, sf::Transform parentTransform = sf::Transform::Identity);

protected:
	TransformNode *m_Parent;
	std::vector<TransformNode *> m_Children;
	sf::Shape *m_Shape;

};

#endif