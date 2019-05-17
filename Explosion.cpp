#include "Explosion.h"

Explosion::Explosion(sf::Sprite* body, sf::RenderWindow* window)
{
	currentXPosition = 0;
	currentYPosition = 0;
	States = 0;

	Body = body;
	Window = window;

	textureExplosion.loadFromFile("images/explosion.png");
	Body->setTexture(textureExplosion);
	Body->setTextureRect(sf::IntRect(currentXPosition, currentYPosition, ANIMATION_WIDTH, ANIMATION_HEIGHT));
	Body->setScale(3.0f, 2.0f);
}

Explosion::~Explosion()
{
}

bool Explosion::updateExplosion()
{
	if (currentXPosition >= MAX_X_TEXTURE && currentYPosition >= MAX_Y_TEXTURE)
		return false; // Check is the animations done

	if (AnimClock.getElapsedTime() >= AnimDelay)
	{
		if (currentXPosition >= MAX_X_TEXTURE)
		{
			AnimClock.restart();
			currentXPosition = 0;
			currentYPosition++;
			Body->setTextureRect(sf::IntRect(currentXPosition * ANIMATION_WIDTH, currentYPosition * ANIMATION_HEIGHT, ANIMATION_HEIGHT, ANIMATION_WIDTH));
			return true;
		}
		else
		{
			AnimClock.restart();
			currentXPosition++;
			Body->setTextureRect(sf::IntRect(currentXPosition * ANIMATION_WIDTH, currentYPosition * ANIMATION_HEIGHT, ANIMATION_HEIGHT, ANIMATION_WIDTH));
			return true;
		}
	}
	else
	{
		return true;
	}
}

void Explosion::drawExplosion()
{
	Window->draw(*Body);
}

/*Explosion Gestion*/
ExplosionGestion::ExplosionGestion(sf::RenderWindow *window)
{
	Window = window;
}

void ExplosionGestion::addExplosion(sf::Sprite* body)
{
	Explosion* ex = new Explosion(body, Window);
	ExplosionList.push_back(ex);
}

void ExplosionGestion::updateExplosions()
{
	for (unsigned int i = 0; i < ExplosionList.size(); i++)
	{
		/* If the Animation is done, free the memory */
		if (!ExplosionList[i]->updateExplosion())
		{
			delete(ExplosionList[i]);
			ExplosionList.erase(ExplosionList.begin() + i);
		}
	}
}

void ExplosionGestion::drawExplosions()
{
	for (unsigned int i = 0; i < ExplosionList.size(); i++)
		ExplosionList[i]->drawExplosion();
}

void ExplosionGestion::clearExplosion()
{
	ExplosionList.clear();
}