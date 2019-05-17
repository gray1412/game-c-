
#include "Bullet.h"

Bullet::Bullet(sf::Vector2f playerPosition)
{
	textureBullet.loadFromFile("images/bullet.png");
	spriteBullet.setTexture(textureBullet);
	spriteBullet.setPosition(playerPosition.x + 40.0f, playerPosition.y); // bullet start at middle of player, cause rect of player = 10 so ...
	spriteBullet.setScale(0.3f, 0.3f);
}

Bullet::~Bullet()
{

}

bool Bullet::updateBullet()
{
	spriteBullet.move(0.0f, -speed);

	// Checking is Bullet out of Window
	if (spriteBullet.getPosition().y < 0.0f /*Cause Bullet move up*/)
		return true;
	return false;
}

void Bullet::drawBullet(sf::RenderWindow &window)
{
	window.draw(spriteBullet);
}

sf::FloatRect Bullet::getBound()
{
	return spriteBullet.getGlobalBounds();
}

void BulletSystem::addBullet(sf::Vector2f playerPosition)
{
	Bullet b(playerPosition);
	BulletContainer.push_back(b);
}

void BulletSystem::updateBullets()
{
	for (unsigned int i = 0; i < BulletContainer.size(); i++)
	{

		if (BulletContainer[i].updateBullet())
		{
			BulletContainer.erase(BulletContainer.begin() + i);
		}
	}
}

void BulletSystem::drawBullets(sf::RenderWindow &window)
{
	for (unsigned int i = 0; i < BulletContainer.size(); i++)
		BulletContainer[i].drawBullet(window);
}

void BulletSystem::deleteBullet(int j)
{
	BulletContainer.erase(BulletContainer.begin() + j);
}

void BulletSystem::clearBullets()
{
	BulletContainer.clear();
}

unsigned int* BulletSystem::getBulletNumber()
{
	return &BulletCount;
}

std::vector<Bullet>* BulletSystem::getList()
{
	return &BulletContainer;
}
