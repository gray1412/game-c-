#pragma once

#include "Player.h"
#include "GameInputs.h"

void Introduction(sf::RenderWindow &window, int numberOfImage);

class TheEnd
{
public:
	TheEnd();
	virtual ~TheEnd();
	void drawVictoryWindow(sf::RenderWindow &window);
	void drawDefeatWindow(sf::RenderWindow &window);

	bool isWin = false;
	bool isLoss = false;

private:
	sf::Sprite spriteVictory;
	sf::Texture textureVictory;

	sf::Sprite spriteDefeat;
	sf::Texture textureDefeat;

};

