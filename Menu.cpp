#pragma once

#include "Menu.h"

Menu::Menu()
{
	textureBackgroundMenu.loadFromFile("images/Menu.png");
	spriteBackgroundMenu.setTexture(textureBackgroundMenu);

	textureButtonPlay.loadFromFile("images/ButtonPlay.png");
	spriteButtonPlay.setTexture(textureButtonPlay);
	spriteButtonPlay.setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON_PLAY, HIGHT_BUTTON));
	spriteButtonPlay.setPosition(455.0f, 350.0f);

	textureButtonIntro.loadFromFile("images/ButtonIntro.png");
	spriteButtonIntro.setTexture(textureButtonIntro);
	spriteButtonIntro.setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON_INTRO, HIGHT_BUTTON_INTRO));
	spriteButtonIntro.setPosition(355.0f, 420.0f);

	/*textureButtonOption.loadFromFile("images/ButtonOption.png");
	spriteButtonOption.setTexture(textureButtonOption);
	spriteButtonOption.setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON_OPTION, HIGHT_BUTTON));
	spriteButtonOption.setPosition(395.0f, 420.0f);

	textureButtonMore.loadFromFile("images/ButtonMoreGames.png");
	spriteButtonMore.setTexture(textureButtonMore);
	spriteButtonMore.setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON_MORE, HIGHT_BUTTON));
	spriteButtonMore.setPosition(360.0f, 475.0f);*/

	textureButtonQuit.loadFromFile("images/ButtonQuit.png");
	spriteButtonQuit.setTexture(textureButtonQuit);
	spriteButtonQuit.setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON_QUIT, HIGHT_BUTTON));
	spriteButtonQuit.setPosition(470.0f, 500.0f);

}

void Menu::drawMenu(sf::RenderWindow &window)
{
	window.draw(spriteBackgroundMenu);
	window.draw(spriteButtonPlay);
	window.draw(spriteButtonIntro);
	/*window.draw(spriteButtonOption);
	window.draw(spriteButtonMore);*/
	window.draw(spriteButtonQuit);
}

void Menu::updateMenu(sf::RenderWindow &window)
{
	if (isChangeWindow == false)
	{
		if (isOnButton(&spriteButtonPlay, (float)WIDTH_BUTTON_PLAY, (float)HIGHT_BUTTON, window))
		{
			spriteButtonPlay.setTextureRect(sf::IntRect(WIDTH_BUTTON_PLAY, 0, WIDTH_BUTTON_PLAY, HIGHT_BUTTON));
			if (isClicked() == true) {
				isPlay = true;
				isChangeWindow = true;
			}
		}
		else spriteButtonPlay.setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON_PLAY, HIGHT_BUTTON));

		if (isOnButton(&spriteButtonIntro, (float)WIDTH_BUTTON_INTRO, (float)HIGHT_BUTTON_INTRO, window))
		{
			spriteButtonIntro.setTextureRect(sf::IntRect(WIDTH_BUTTON_INTRO, 0, WIDTH_BUTTON_INTRO, HIGHT_BUTTON_INTRO));
			if (isClicked() == true) {
				isIntro = true;
				isChangeWindow = true;
			}
		}
		else spriteButtonIntro.setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON_INTRO, HIGHT_BUTTON_INTRO));

		/*if (isOnButton(&spriteButtonOption, (float)WIDTH_BUTTON_OPTION, (float)HIGHT_BUTTON, window))
		{
			spriteButtonOption.setTextureRect(sf::IntRect(WIDTH_BUTTON_OPTION, 0, WIDTH_BUTTON_OPTION, HIGHT_BUTTON));
			if (isClicked() == true) {
				isOption = true;
				isChangeWindow = true;
			}
		}
		else spriteButtonOption.setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON_OPTION, HIGHT_BUTTON));

		if (isOnButton(&spriteButtonMore, (float)WIDTH_BUTTON_MORE, (float)HIGHT_BUTTON, window))
		{
			spriteButtonMore.setTextureRect(sf::IntRect(WIDTH_BUTTON_MORE, 0, WIDTH_BUTTON_MORE, HIGHT_BUTTON));
			if (isClicked() == true) {
				isMore = true;
				isChangeWindow = true;
			}
		}
		else spriteButtonMore.setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON_MORE, HIGHT_BUTTON));*/

		if (isOnButton(&spriteButtonQuit, (float)WIDTH_BUTTON_QUIT, (float)HIGHT_BUTTON, window))
		{
			spriteButtonQuit.setTextureRect(sf::IntRect(WIDTH_BUTTON_QUIT, 0, WIDTH_BUTTON_QUIT, HIGHT_BUTTON));
			if (isClicked() == true) {
				isQuit = true;
				isChangeWindow = true;
			}
		}
		else spriteButtonQuit.setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON_QUIT, HIGHT_BUTTON));
	
	}
}


