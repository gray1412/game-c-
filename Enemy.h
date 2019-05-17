#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bullet.h"
#include "Explosion.h"

#define MAX_ENEMY_NUMBER 20

#define MAX_X_TEXTURE 4
#define MAX_Y_TEXTURE 4
#define ANIMATION_WIDTH 250
#define ANIMATION_HEIGHT 100

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();
	void updateEnemy();
	void drawEnemy(sf::RenderWindow &window);
	sf::Sprite* getBody();
	sf::FloatRect getBound();
	sf::Vector2f getPosition();

private:
	unsigned int currentXPosition = 0;
	unsigned int currentYPosition = 0;
	sf::Clock AnimClock;
	const sf::Time AnimDelay = sf::milliseconds(100); // Animation delay
	
	float speed = 1.0f;

	sf::Texture textureEnemy;
	sf::Sprite spriteEnemy;
};

class EnemySystem
{
public:
	EnemySystem(std::vector<Bullet>* bulletsList, unsigned int* bulletCount, sf::RenderWindow *window);
	
	std::vector<Enemy*>* getEnemyList();
	
	int getEnemyNumber();
	unsigned int* getKilledNumber();

	void updateEnemies(sf::RenderWindow* window);
	void drawEnemies(sf::RenderWindow &window);
	void resetEnemy();
	bool isOutOfWindow = false;

private:
	bool isCollided(sf::FloatRect a, sf::FloatRect b);
	void creatEnemies();
	void deleteEnemy(Enemy* e, unsigned int position, sf::RenderWindow* window);

	sf::Clock AddClock;
	const sf::Time AddDelay = sf::milliseconds(300);
	ExplosionGestion Explosions;

	std::vector<Enemy*> EnemyList;
	std::vector<Bullet>* BulletsList = nullptr;
	unsigned int* p_BulletCount = nullptr;
	int EnemyNumber = 0;
	unsigned int KilledNumber = 0;
};

