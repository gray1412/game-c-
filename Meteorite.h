#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Explosion.h"

#define MAX_METEORITE_NUMBER 5

#define MAX_TEXTURE_METEORITE 3
#define ANIMATION_WIDTH_METEORITE 150
#define ANIMATION_HEIGHT_METEORITE 360

class Meteorite
{
public:
	Meteorite();
	virtual ~Meteorite();
	void updateMeteorite();
	void drawMeteorite(sf::RenderWindow &window);
	sf::FloatRect getBound();
	sf::Vector2f getPosition();

private:
	unsigned int currentPosition = 0;
	sf::Clock AnimClock;
	const sf::Time AnimDelay = sf::milliseconds(50);
	bool isEndAnimation = false;

	float speed = 3.0f;

	sf::Sprite spriteMeteorite;
	sf::Texture textureMeteorite;
};

class MeteoriteSystem
{
public:
	MeteoriteSystem();

	std::vector<Meteorite*>* getMeteoriteList();

	void updateMeteorites(sf::RenderWindow* window);
	void drawMeteorites(sf::RenderWindow &window);
	void resetMeteorite();

private:
	void creatMeteorites();
	void deleteMeteorite(Meteorite* m, unsigned int position, sf::RenderWindow* window);

	sf::Clock AddClock;
	const sf::Time AddDelay = sf::milliseconds(500);
	//ExplosionGestion2 Explosion;

	std::vector<Meteorite*> MeteoriteList;
	unsigned int* p_MeteoriteCount = nullptr;
	int MeteoriteNumber = 0;
};