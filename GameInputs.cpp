#include "GameInputs.h"

keysPressed isKeyPressed()
{
	keysPressed keys;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		keys.rightArrow = true;
		return keys;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		keys.leftArrow = true;
		return keys;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		keys.spaceBar = true;
		return keys;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		keys.returnKey = true;
		return keys;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		keys.escKey = true;
		return keys;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		keys.upKey = true;
		return keys;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		keys.downKey = true;
		return keys;
	}
	else
	{
		return keys;
	}
}

bool isOnButton(sf::Sprite* button, float length, float hight, sf::RenderWindow &window)
{
	return (
			(button->getPosition().x <= (float)sf::Mouse::getPosition(window).x) 
		&& (button->getPosition().x >= (float)sf::Mouse::getPosition(window).x - length)
		&& (button->getPosition().y <= (float)sf::Mouse::getPosition(window).y)
		&& (button->getPosition().y >= (float)sf::Mouse::getPosition(window).y - hight)
		);
}

bool isClicked()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
