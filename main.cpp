
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "TheEnd.h"
#include "Player.h"

const int Width = 1200;
const int Hight = 600;

int main()
{
	sf::RenderWindow app(sf::VideoMode(Width, Hight), "Infinity Space War");
	app.setFramerateLimit(60);

	Menu menu;
	TheEnd theEnd;
	keysPressed key = isKeyPressed();
	int NumberOfImage = 1;
	int maxImage = 4;

	sf::Clock AddClock;
	const sf::Time TimeDelayAdd = sf::milliseconds(200);

	sf::Sprite spriteBackground;
	sf::Texture textureBackground;
	textureBackground.loadFromFile("images/Background.png");
	spriteBackground.setTexture(textureBackground);

	Player player;
	BulletSystem bullets;
	EnemySystem enemies(bullets.getList(), bullets.getBulletNumber(), &app);
	MeteoriteSystem meteorites;
	BossEnemy boss(bullets.getList(), bullets.getBulletNumber());


	while (app.isOpen())
	{
		sf::Event e;
		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				app.close();
		}

		app.clear();
		if (menu.isCombackMenu == true)
		{
			menu.drawMenu(app);
			menu.updateMenu(app);
		}

		if (menu.isPlay == true)
		{
			menu.isCombackMenu = false;
			player.movement(app);

			/*Fire bullet*/
			if (AddClock.getElapsedTime() >= TimeDelayAdd)
			{
				AddClock.restart();
				bullets.addBullet(player.getPosition());
			}

			/*Update*/
			bullets.updateBullets();
			enemies.updateEnemies(&app);
			meteorites.updateMeteorites(&app);
			boss.updateBoss();

			/*Draw*/
			app.draw(spriteBackground);
			player.drawPlayer(app);
			bullets.drawBullets(app);
			enemies.drawEnemies(app);
			meteorites.drawMeteorites(app);
			boss.drawBoss(app);

			if ((player.isDead(enemies.getEnemyList(), meteorites.getMeteoriteList())) || (enemies.isOutOfWindow))
			{
				enemies.resetEnemy();
				bullets.clearBullets();
				meteorites.resetMeteorite();
				menu.isPlay = false;
				theEnd.isLoss = true;
			}

			if (boss.isKilled == true)
			{
				enemies.resetEnemy();
				bullets.clearBullets();
				meteorites.resetMeteorite();
				menu.isPlay = false;
				theEnd.isWin = true;
			}
		}

		/*End Game*/
		if (theEnd.isWin == true)
		{
			theEnd.drawVictoryWindow(app);
			if (key.returnKey == true)
			{
				menu.isCombackMenu = true;
				theEnd.isWin = false;
				menu.isChangeWindow = false;
			}
			key = isKeyPressed();
		}

		if (theEnd.isLoss == true)
		{
			theEnd.drawDefeatWindow(app);
			if (key.returnKey == true)
			{
				menu.isCombackMenu = true;
				theEnd.isLoss = false;
				menu.isChangeWindow = false;
			}
			key = isKeyPressed();
		}

		/*Introduction*/
		if (menu.isIntro == true)
		{
			menu.isCombackMenu = false;
			Introduction(app, NumberOfImage);
			if (key.rightArrow && NumberOfImage < maxImage) NumberOfImage++;
			if (key.leftArrow  && NumberOfImage > 0) NumberOfImage--;
			if (key.escKey)
			{
				menu.isCombackMenu = true;
				menu.isChangeWindow = false;
				menu.isIntro = false;
			}
			key = isKeyPressed();
		}

		/*Quit*/
		if (menu.isQuit == true) app.close();

		app.display();
	}
	system("Pause");
	return 0;
}