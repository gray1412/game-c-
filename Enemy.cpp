#include "Enemy.h"

Enemy::Enemy()
{
	textureEnemy.loadFromFile("images/UFO.png");
	spriteEnemy.setTexture(textureEnemy);

	spriteEnemy.setScale(0.4f, 0.4f);
	spriteEnemy.setTextureRect(sf::IntRect(currentXPosition, currentYPosition, ANIMATION_WIDTH, ANIMATION_HEIGHT));
	spriteEnemy.setPosition((float)(rand()% 11 * 100), 0.0f);
}

Enemy::~Enemy()
{

}

void Enemy::updateEnemy()
{
	/*Update Animation*/
	if (AnimClock.getElapsedTime() >= AnimDelay)
	{
		if (currentXPosition >= MAX_X_TEXTURE)
		{
			AnimClock.restart();
			currentXPosition = 0;
			spriteEnemy.setTextureRect(sf::IntRect(currentXPosition * ANIMATION_WIDTH, currentYPosition * ANIMATION_HEIGHT, ANIMATION_WIDTH, ANIMATION_HEIGHT));
			currentYPosition++;
		}
		else
		{
			AnimClock.restart();
			spriteEnemy.setTextureRect(sf::IntRect(currentXPosition * ANIMATION_WIDTH, currentYPosition * ANIMATION_HEIGHT, ANIMATION_WIDTH, ANIMATION_HEIGHT));
			currentXPosition++;
			if (currentYPosition >= MAX_Y_TEXTURE)
			{
				currentXPosition = 0;
				currentYPosition = 0;
			}
		}
	}

	/*Update Movement*/
	spriteEnemy.move(0.0f, speed);
}

void Enemy::drawEnemy(sf::RenderWindow &window)
{
	window.draw(spriteEnemy);
}

sf::Sprite* Enemy::getBody()
{
	return &spriteEnemy;
}

sf::FloatRect Enemy::getBound()
{
	return spriteEnemy.getGlobalBounds();
}

sf::Vector2f Enemy::getPosition()
{
	return spriteEnemy.getPosition();
}

/* Enemy System */
EnemySystem::EnemySystem(std::vector<Bullet>* bulletsList, unsigned int* bulletCount, sf::RenderWindow *window)
{
	BulletsList = bulletsList;
	p_BulletCount = bulletCount;

	ExplosionGestion ex(window);
	Explosions = ex;
}

std::vector<Enemy*>* EnemySystem::getEnemyList()
{
	return &EnemyList;
}

int EnemySystem::getEnemyNumber()
{
	return EnemyNumber;
}

unsigned int* EnemySystem::getKilledNumber()
{
	return &KilledNumber;
}

bool EnemySystem::isCollided(sf::FloatRect a, sf::FloatRect b)
{
	return a.intersects(b);
}

void EnemySystem::updateEnemies(sf::RenderWindow* window)
{
	/* Check if an Ennemy is out of Window or Shooted*/
	 /* If an Ennemy if is shooted -> launch death Animation*/
	for (unsigned int i = 0; i < EnemyList.size(); i++)
	{
		for (unsigned int j = 0; j < BulletsList->size(); j++)
		{
			if (isCollided(EnemyList[i]->getBound(), (*BulletsList)[j].getBound()))
			{
				deleteEnemy(EnemyList[i], i/*, Shooted*/, window);

				BulletsList->erase(BulletsList->begin() + j);
				*p_BulletCount = BulletsList->size();

				return;
			}
		}
	}

	/* Else the ennemy is out of window -> delete it*/
	for (unsigned int i = 0; i < EnemyList.size(); i++)
	{
		EnemyList[i]->updateEnemy();

		if (EnemyList[i]->getPosition().y >= 600)
		{
			isOutOfWindow = true;
			return;
		}
	}

	/*Creat Enemies*/
	if (AddClock.getElapsedTime() >= AddDelay)
	{
		creatEnemies();
		AddClock.restart();
	}

	/*Update Animation and Movement*/
	for (int i = 0; i < EnemyList.size(); i++)
	{
		EnemyList[i]->updateEnemy();
	}

	/*Update Animation of Explosion*/
	Explosions.updateExplosions();
}

void EnemySystem::creatEnemies()
{
	if (EnemyList.size() < MAX_ENEMY_NUMBER)
	{
		Enemy *e = new(Enemy);
		EnemyList.push_back(e);
	}
}

void EnemySystem::drawEnemies(sf::RenderWindow &window)
{
	for (unsigned int i = 0; i < EnemyList.size(); i++)
		EnemyList[i]->drawEnemy(window);

	Explosions.drawExplosions();
}

void EnemySystem::resetEnemy()
{
	EnemyNumber = 0;
	Explosions.clearExplosion();
	EnemyList.clear();
}

void EnemySystem::deleteEnemy(Enemy* e, unsigned int position, sf::RenderWindow* window)
{
	Explosions.addExplosion(e->getBody());
	EnemyList.erase(EnemyList.begin() + position);
}