#pragma once
#include <SFML/Graphics.hpp>

struct keysPressed
{
	bool leftArrow = false;
	bool rightArrow = false;
	bool spaceBar = false;
	bool returnKey = false;
	bool escKey = false;
	bool upKey = false;
	bool downKey = false;
};

keysPressed isKeyPressed();

bool isOnButton(sf::Sprite* button, float length, float hight, sf::RenderWindow &window);

bool isClicked();