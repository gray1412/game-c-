
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "GameInputs.h"

void Introduction(sf::RenderWindow &window, int numberOfImage)
{
	sf::Sprite spriteIntro;
	sf::Texture textureIntro;

	std::string nameImage = "images/Intro";
	
	switch (numberOfImage)
	{
	case 1:
		nameImage += "1.png";
		break;
	case 2:
		nameImage += "2.png";
		break;
	case 3:
		nameImage += "3.png";
		break;
	default:
		nameImage += "4.png";
		break;
	}

	textureIntro.loadFromFile(nameImage);
	spriteIntro.setTexture(textureIntro);
	window.draw(spriteIntro);
	
}