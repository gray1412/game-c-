#include "Player.h"

Player::Player()
{
	texturePlayer.loadFromFile("images/spaceship.png");
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setScale(0.1f, 0.1f);
}

Player::~Player()
{

}

void Player::update()
{
	/*I will write here in next upgrade version*/
}

void Player::drawPlayer(sf::RenderWindow &window)
{
	window.draw(spritePlayer);
}

void Player::movement(sf::RenderWindow &window)
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(window);
	spritePlayer.setPosition((float)localPosition.x - 40.0f, (float)localPosition.y -35.0f);
}

sf::FloatRect Player::getBound()
{
	return spritePlayer.getGlobalBounds();
}

sf::Vector2f Player::getPosition()
{
	return sf::Vector2f(spritePlayer.getPosition().x, spritePlayer.getPosition().y);
}

bool Player::isDead(std::vector<Enemy*>* enemyList, std::vector<Meteorite*>* meteoriteList)
{
	for (unsigned int i = 0; i < enemyList->size(); i++)
	{
		//Checking Collision of 2 Bounds's sprite
		if ((*enemyList)[i]->getBound().intersects(spritePlayer.getGlobalBounds()))
		{
			enemyList->erase(enemyList->begin() + i);
			delete((*enemyList)[i]);

			return true;
		}
	}

	for (unsigned int i = 0; i < meteoriteList->size(); i++)
	{
		//Checking Collision of 2 Bounds's sprite
		if ((*meteoriteList)[i]->getBound().intersects(spritePlayer.getGlobalBounds()))
		{
			meteoriteList->erase(meteoriteList->begin() + i);
			delete((*meteoriteList)[i]);

			return true;
		}
	}

	return false;
}