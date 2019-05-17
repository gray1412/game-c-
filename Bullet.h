#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class Bullet
{
public:
	Bullet(sf::Vector2f playerPosition);
	virtual ~Bullet();
	bool updateBullet(); // Checking is it out of window, too
	void drawBullet(sf::RenderWindow &window);
	sf::FloatRect getBound();

private:
	sf::Sprite spriteBullet;
	sf::Texture textureBullet;
	float speed = 10.0f;
};

class BulletSystem
{
public:
	void addBullet(sf::Vector2f playerPosition);
	void updateBullets();
	void drawBullets(sf::RenderWindow &window);
	void deleteBullet(int j);
	void clearBullets();

	unsigned int* getBulletNumber();
	std::vector<Bullet>* getList();

private:
	unsigned int BulletCount = 0;
	std::vector<Bullet> BulletContainer;
};


