#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_X_TEXTURE 4
#define MAX_Y_TEXTURE 4
#define ANIMATION_WIDTH 64
#define ANIMATION_HEIGHT 64

class Explosion
{
public:
	Explosion(sf::Sprite* body, sf::RenderWindow* window);
	virtual ~Explosion();
	bool updateExplosion();
	void drawExplosion();

private:
	unsigned int currentXPosition;
	unsigned int currentYPosition;

	sf::Clock AnimClock;
	const sf::Time AnimDelay = sf::milliseconds(50); // Animation delay

	sf::RenderWindow* Window = nullptr;
	sf::Sprite* Body;
	sf::Texture textureExplosion;
	unsigned int States;
};

class ExplosionGestion
{
public:
	ExplosionGestion(sf::RenderWindow *window = nullptr);
	void updateExplosions();
	void addExplosion(sf::Sprite* body);
	void drawExplosions();
	void clearExplosion();

private:
	std::vector<Explosion*> ExplosionList;
	sf::RenderWindow *Window = nullptr;

};
