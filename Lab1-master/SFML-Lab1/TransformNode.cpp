#include "TransformNode.h"

TransformNode::TransformNode(sf::Shape *shape) : m_Shape(shape) {}

bool TransformNode::addChild(TransformNode *child) {
	if (child != nullptr && child != this && !hasChild(child)) {
		//add children to vector
		m_Children.push_back(child);
		child->m_Parent = this;
		return true;
	}

	return false;
}

bool TransformNode::removeChild(TransformNode *child) {
	if (child != nullptr && child != this /*&& hasChild(child)*/) {
		auto itr = std::find(m_Children.begin(), m_Children.end(), child);
		if (itr != m_Children.end()) {
			m_Children.erase(itr);
			return true;
		}
	}

	return false;
}

bool TransformNode::hasChild(TransformNode *child) {
	//TODO:: addrecursion
	auto itr = std::find(m_Children.begin(), m_Children.end(), child);
	return (itr != m_Children.end());
}

void TransformNode::draw(sf::RenderTarget *target, sf::Transform parentTransform) {
	target->draw(*m_Shape, parentTransform);	
	
	sf::Transform hierchy = parentTransform * m_Shape->getTransform();

	for (int childIndex = 0; childIndex < m_Children.size(); childIndex++)
		m_Children[childIndex]->draw(target, hierchy);
}