#include "BossEnemy.h"

BossEnemy::BossEnemy(std::vector<Bullet>* bulletsList, unsigned int* bulletCount)
{
	BulletsList = bulletsList;
	p_BulletCount = bulletCount;

	textureBoss.loadFromFile("images/Boss.png");
	spriteBoss.setTexture(textureBoss);
	spriteBoss.setTextureRect(sf::IntRect(currentPosition, 0, ANIMATION_WIDTH, ANIMATION_HEIGHT));
	spriteBoss.setPosition(400.0f, 0.0f);

	textureHP.loadFromFile("images/hp.png");
	spriteHP.setTexture(textureHP);
	spriteHP.setPosition(400.0f, (float)ANIMATION_HEIGHT);
	spriteBoss.setTextureRect(sf::IntRect(0, 0, 10, ANIMATION_HEIGHT));
}

BossEnemy::~BossEnemy()
{
}

void BossEnemy::updateBoss()
{
	/*Update Animation*/
	if (AnimClock.getElapsedTime() >= AnimDelay)
	{
		if (isEndAnimation == false)
		{
			AnimClock.restart();
			spriteBoss.setTextureRect(sf::IntRect(currentPosition * ANIMATION_WIDTH, 0, ANIMATION_WIDTH, ANIMATION_HEIGHT));
			currentPosition++;
			if (currentPosition == MAX_TEXTURE) isEndAnimation = true;
		}
		else {
			AnimClock.restart();
			spriteBoss.setTextureRect(sf::IntRect(currentPosition * ANIMATION_WIDTH, 0, ANIMATION_WIDTH, ANIMATION_HEIGHT));
			currentPosition--;
			if (currentPosition == 0) isEndAnimation = false;
		}
	}

	/*Update Movement*/
	if (isRight == false)
	{
		spriteBoss.move(speed, 0.0f);
		spriteHP.move(speed, 0.0f);
		if (spriteBoss.getPosition().x == 850.0f)
		{
			isRight = true;
		}	
	}
	else {
		spriteBoss.move(-speed, 0.0f);
		spriteHP.move(-speed, 0.0f);
		if (spriteBoss.getPosition().x == 0.0f)
			isRight = false;
	}

	/*Update Collidtion and HP*/
	for (int i = 0; i < BulletsList->size(); i++)
	{
		if (isCollided(BossEnemyBound(), (*BulletsList)[i].getBound()))
		{
			HP -= damge;
			BulletsList->erase(BulletsList->begin() + i);
			*p_BulletCount = BulletsList->size();
			spriteHP.setTextureRect(sf::IntRect(0, 0, HP, 10));
			break;
		}
	}

	/*Update isLife*/
	if (HP <= 0) isKilled = true;
}

void BossEnemy::drawBoss(sf::RenderWindow &window)
{
	window.draw(spriteBoss);
	window.draw(spriteHP);
}

sf::FloatRect BossEnemy::BossEnemyBound()
{
	return spriteBoss.getGlobalBounds();
}

bool BossEnemy::isCollided(sf::FloatRect a, sf::FloatRect b)
{
	return a.intersects(b);
}

