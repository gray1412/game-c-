#include "TheEnd.h"



TheEnd::TheEnd()
{
	textureVictory.loadFromFile("images/Victory.png");
	spriteVictory.setTexture(textureVictory);

	textureDefeat.loadFromFile("images/Defeat.png");
	spriteDefeat.setTexture(textureDefeat);
}

TheEnd::~TheEnd()
{
}

void TheEnd::drawVictoryWindow(sf::RenderWindow &window)
{
	window.draw(spriteVictory);
}

void TheEnd::drawDefeatWindow(sf::RenderWindow &window)
{
	window.draw(spriteDefeat);
}