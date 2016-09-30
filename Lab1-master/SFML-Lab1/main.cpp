#include <SFML/Graphics.hpp>
#include "TransformNode.h"
#include <iostream>

int main(int argc, char* argv) {
	sf::RenderWindow window(sf::VideoMode(600, 500), "Air Dancerz");  
	bool rightUpperNegFlag = false;
	bool rightLowerNegFlag = false;
	bool leftLowerNegFlag = false;
	bool leftUpperNegFlag = false;
	bool torsoNegFlag = false;
	bool neckNegFlag = false;
	bool headNegFlag = false;

	// create shapes
	sf::CircleShape circle(30, 30);
	sf::RectangleShape torsoRect(sf::Vector2<float>(30.0f, 250.0f));
	sf::RectangleShape rightLowerArmRect(sf::Vector2<float>(100.0f, 15.0f));
	sf::RectangleShape rightUpperArmRect(sf::Vector2<float>(100.0f, 15.0f));
	sf::RectangleShape leftLowerArmRect(sf::Vector2<float>(100.0f, 15.0f));
	sf::RectangleShape leftUpperArmRect(sf::Vector2<float>(100.0f, 15.0f));
	sf::RectangleShape neckRect(sf::Vector2<float>(50.0f, 10.0f));

	// set colours
	circle.setFillColor(sf::Color::Blue);
	torsoRect.setFillColor(sf::Color::Blue);
	rightLowerArmRect.setFillColor(sf::Color::Blue);
	rightUpperArmRect.setFillColor(sf::Color::Blue);
	leftLowerArmRect.setFillColor(sf::Color::Blue);
	leftUpperArmRect.setFillColor(sf::Color::Blue);
	neckRect.setFillColor(sf::Color::Blue);

	// set origin and position of parent rect.
	torsoRect.setOrigin(15.0f, 250.0f);
	torsoRect.setPosition(300, 510);

	// set position of right arm
	rightUpperArmRect.setPosition(torsoRect.getLocalBounds().width-2.0f, 0.0f);
	rightLowerArmRect.setPosition(100.0f, 0.0f);

	// set position of left arm
	leftUpperArmRect.setPosition(2.0f, 15.0f);
	leftUpperArmRect.setRotation(180.0f);
	leftLowerArmRect.setPosition(100.0, 0.0f);

	// set position of neck and head
	neckRect.setRotation(270.0f);
	neckRect.setPosition(10.0f, 2.0f);
	circle.setOrigin(-45.0f, 25.0f);

	// create nodes
	TransformNode head(&circle);
	TransformNode rightUpperArm(&rightUpperArmRect);
	TransformNode rightLowerArm(&rightLowerArmRect);
	TransformNode leftUpperArm(&leftUpperArmRect);
	TransformNode leftLowerArm(&leftLowerArmRect);
	TransformNode torso(&torsoRect);
	TransformNode neck(&neckRect);

	// add children
	rightUpperArm.addChild(&rightLowerArm);
	leftUpperArm.addChild(&leftLowerArm);
	torso.addChild(&rightUpperArm);
	torso.addChild(&leftUpperArm);
	neck.addChild(&head);
	torso.addChild(&neck);

	sf::Clock deltaTime;
	while (window.isOpen()) {
		// time elapsed since last loop
		float elapsedTime = deltaTime.restart().asSeconds();
		sf::Event sfEvent;
		// close window when x is pressed
		while (window.pollEvent(sfEvent))
			if (sfEvent.type == sf::Event::Closed)
				window.close();

		// calculate movement amounts for each shape
		float headMovement = 90.0f * elapsedTime;
		float torsoMovement = 60.0f * elapsedTime;
		float rightUpperMovement = 100.0f * elapsedTime;
		float leftUpperMovement = 100.0f * elapsedTime;
		float rightLowerMovement = 120.0f * elapsedTime;
		float leftLowerMovement = 190.0f * elapsedTime;

		// rotate torso
		float torsoRotation = torsoRect.getRotation();
		if (torsoNegFlag == false)
			torsoRect.rotate(torsoMovement);
		if (torsoNegFlag == true)
			torsoRect.rotate(-torsoMovement);
		if (torsoRotation > 25.0f && torsoRotation < 30.0f)
			torsoNegFlag = true;
		if (torsoRotation < 340.0f && torsoRotation > 335.0f)
			torsoNegFlag = false;

		// rotate right upper arm
		float rightUpperRotation = rightUpperArmRect.getRotation();
		if (rightUpperNegFlag == false)
			rightUpperArmRect.rotate(rightUpperMovement);
		if (rightUpperNegFlag == true)
			rightUpperArmRect.rotate(-rightUpperMovement);
		if (rightUpperRotation > 35.0f && rightUpperRotation < 40.0f)
			rightUpperNegFlag = true;
		if (rightUpperRotation < 330.0f && rightUpperRotation > 325.0f)
			rightUpperNegFlag = false;

		// rotate right lower arm
		float rightLowerRotation = rightLowerArmRect.getRotation();
		if (rightLowerNegFlag == false)
			rightLowerArmRect.rotate(rightLowerMovement);
		if (rightLowerNegFlag == true)
			rightLowerArmRect.rotate(-rightLowerMovement);
		if (rightLowerRotation > 35.0f && rightLowerRotation < 40.0f)
			rightLowerNegFlag = true;
		if (rightLowerRotation < 330.0f && rightLowerRotation > 325.0f)
			rightLowerNegFlag = false;

		// rotate left upper arm
		float leftUpperRotation = leftUpperArmRect.getRotation();
		if (leftUpperNegFlag == false)
			leftUpperArmRect.rotate(leftUpperMovement);
		if (leftUpperNegFlag == true)
			leftUpperArmRect.rotate(-leftUpperMovement);
		if (leftUpperRotation > 215.0f && leftUpperRotation < 220.0f)
			leftUpperNegFlag = true;
		if (leftUpperRotation < 145.0f && leftUpperRotation > 140.0f)
			leftUpperNegFlag = false;

		// rotate left lower arm
		float leftLowerRotation = leftLowerArmRect.getRotation();
		if (leftLowerNegFlag == false)
			leftLowerArmRect.rotate(leftLowerMovement);
		if (leftLowerNegFlag == true)
			leftLowerArmRect.rotate(-leftLowerMovement);
		if (leftLowerRotation > 35.0f && leftLowerRotation < 40.0f)
			leftLowerNegFlag = true;
		if (leftLowerRotation < 330.0f && leftLowerRotation > 325.0f)
			leftLowerNegFlag = false;
		
		// rotate neck
		float neckRotation = neckRect.getRotation();
		if (neckNegFlag == false)
			neckRect.rotate(headMovement);
		if (neckNegFlag == true)
			neckRect.rotate(-headMovement);
		if (neckRotation > 305.0f && neckRotation < 310.0f)
			neckNegFlag = true;
		if (neckRotation < 240.0f && neckRotation > 235.0f)
			neckNegFlag = false;

		// rotate head
		float headRotation = circle.getRotation();
		if (headNegFlag == false)
			circle.rotate(headMovement);
		if (headNegFlag == true)
			circle.rotate(-headMovement);
		if (headRotation > 15.0f && headRotation < 20.0f)
			headNegFlag = true;
		if (headRotation < 350.0f && headRotation > 345.0f)
			headNegFlag = false;

		window.clear(); // clear display
		torso.draw(&window); // draw all shapes
		window.display(); // display!
	}
  return 0;
}