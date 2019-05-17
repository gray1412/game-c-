#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include "Bullet.h"

#define MAX_TEXTURE 11
#define ANIMATION_WIDTH 350
#define ANIMATION_HEIGHT 250

class BossEnemy
{
public:
	BossEnemy(std::vector<Bullet>* bulletsList, unsigned int* bulletCount);
	virtual ~BossEnemy();
	void updateBoss();
	void drawBoss(sf::RenderWindow &window);

	sf::FloatRect BossEnemyBound();

	bool isKilled = false;

private:
	unsigned int currentPosition = 0;
	float speed = 1.0f;
	bool isRight = false;

	bool isCollided(sf::FloatRect a, sf::FloatRect b);

	std::vector<Bullet>* BulletsList = nullptr;
	unsigned int* p_BulletCount = nullptr;

	bool isEndAnimation = false;
	sf::Clock AnimClock;
	const sf::Time AnimDelay = sf::milliseconds(200); // Animation delay

	unsigned int HP = 350;
	unsigned int damge = 5;

	sf::Texture textureBoss;
	sf::Sprite spriteBoss;

	sf::Texture textureHP;
	sf::Sprite spriteHP;
};

