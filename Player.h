#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include "Enemy.h"
#include "Meteorite.h"
#include "BossEnemy.h"

class Player
{
public:
	Player();
	virtual ~Player();
	void update(); // Update Player after Collietde with Enemy or newPower
	void drawPlayer(sf::RenderWindow &window);
	void movement(sf::RenderWindow &window);

	sf::Vector2f getPosition();
	sf::FloatRect getBound();
	bool isDead(std::vector<Enemy*>* enemyList, std::vector<Meteorite*>* meteoriteList);

private:
	sf::Texture texturePlayer;
	sf::IntRect intRectPlayer;
	sf::Sprite spritePlayer;
};
