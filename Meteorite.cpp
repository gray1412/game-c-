#include "Meteorite.h"

Meteorite::Meteorite()
{
	textureMeteorite.loadFromFile("images/meteorite.png");
	spriteMeteorite.setTexture(textureMeteorite);

	spriteMeteorite.setScale(0.5f, 0.5f);
	spriteMeteorite.setTextureRect(sf::IntRect(currentPosition, 0, ANIMATION_WIDTH_METEORITE, ANIMATION_HEIGHT_METEORITE));
	spriteMeteorite.setPosition((float)(rand() % 16 * 100), 0.0f);
}

Meteorite::~Meteorite()
{
}

void Meteorite::updateMeteorite()
{
	/*Update Animation*/
	if (AnimClock.getElapsedTime() >= AnimDelay)
	{
		if (isEndAnimation == false)
		{
			AnimClock.restart();
			spriteMeteorite.setTextureRect(sf::IntRect(currentPosition * ANIMATION_WIDTH_METEORITE, 0, ANIMATION_WIDTH_METEORITE, ANIMATION_HEIGHT_METEORITE));
			currentPosition++;
			if (currentPosition == MAX_TEXTURE_METEORITE) isEndAnimation = true;
		}
		else {
			AnimClock.restart();
			spriteMeteorite.setTextureRect(sf::IntRect(currentPosition * ANIMATION_WIDTH_METEORITE, 0, ANIMATION_WIDTH_METEORITE, ANIMATION_HEIGHT_METEORITE));
			currentPosition--;
			if (currentPosition == 0) isEndAnimation = false;
		}
	}

	/*Update Movement*/
	spriteMeteorite.move(0.0f, speed);

}

void Meteorite::drawMeteorite(sf::RenderWindow &window)
{
	window.draw(spriteMeteorite);
}

sf::FloatRect Meteorite::getBound()
{
	return spriteMeteorite.getGlobalBounds();
}

sf::Vector2f Meteorite::getPosition()
{
	return spriteMeteorite.getPosition();
}

/*Meteorite System*/
MeteoriteSystem::MeteoriteSystem()
{
}

std::vector<Meteorite*>* MeteoriteSystem::getMeteoriteList()
{
	return &MeteoriteList;
}

void MeteoriteSystem::updateMeteorites(sf::RenderWindow* window)
{
	/* if the meteorite is out of window -> delete it*/
	for (unsigned int i = 0; i < MeteoriteList.size(); i++)
	{
		MeteoriteList[i]->updateMeteorite();

		if (MeteoriteList[i]->getPosition().y >= 550)
		{
			MeteoriteList.erase(MeteoriteList.begin() + i);
			return;
		}
	}

	/*Creat Meteorites*/
	if (AddClock.getElapsedTime() >= AddDelay)
	{
		creatMeteorites();
		AddClock.restart();
	}

	/*Update Animation and Movement*/
	for (int i = 0; i < MeteoriteList.size(); i++)
	{
		MeteoriteList[i]->updateMeteorite();
	}

}

void MeteoriteSystem::creatMeteorites()
{
	if (MeteoriteList.size() < MAX_METEORITE_NUMBER)
	{
		Meteorite *m = new(Meteorite);
		MeteoriteList.push_back(m);
	}
}

void MeteoriteSystem::drawMeteorites(sf::RenderWindow &window)
{
	for (unsigned int i = 0; i < MeteoriteList.size(); i++)
		MeteoriteList[i]->drawMeteorite(window);
}

void MeteoriteSystem::resetMeteorite()
{
	MeteoriteList.clear();
}
