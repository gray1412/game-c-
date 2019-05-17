#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "gameInputs.h"

#define WIDTH_BUTTON_PLAY 290
#define WIDTH_BUTTON_INTRO 490
#define WIDTH_BUTTON_OPTION 355
#define WIDTH_BUTTON_MORE 430
#define WIDTH_BUTTON_QUIT 222
#define HIGHT_BUTTON 63
#define HIGHT_BUTTON_INTRO 75

class Menu
{
public:
	Menu();
	void drawMenu(sf::RenderWindow &window);
	void updateMenu(sf::RenderWindow &window);
	bool isCombackMenu = true;
	bool isChangeWindow = false;
	bool isPlay = false;
	bool isIntro = false;
	/*bool isOption = false;
	bool isMore = false;*/
	bool isQuit = false;

private:
	sf::Sprite spriteBackgroundMenu;
	sf::Texture textureBackgroundMenu;

	sf::Sprite spriteButtonPlay;
	sf::Texture textureButtonPlay;

	sf::Sprite spriteButtonIntro;
	sf::Texture textureButtonIntro;

	/*sf::Sprite spriteButtonOption;
	sf::Texture textureButtonOption;

	sf::Sprite spriteButtonMore;
	sf::Texture textureButtonMore;*/

	sf::Sprite spriteButtonQuit;
	sf::Texture textureButtonQuit;

};

