#include "Enemy.h"

void Enemy::init()
{
	enemy.setSize(sf::Vector2f{ 50, 50 });
	enemy.setFillColor(sf::Color::Green);
	enemy.setPosition(enemyPosition);
}

void Enemy::movement()
{
	if (enemyPosition.x >= 100 && enemyPosition.x <= 200 && backwards == false)
	{
		enemyPosition.x++;

		if (enemyPosition.x >= 200)
		{
			backwards = true;
		}
	}
	if (enemyPosition.x >= 100 && enemyPosition.x <= 200 && backwards == true)
	{
		enemyPosition.x--;
		if (enemyPosition.x <= 100)
		{
			backwards = false;
		}
	}
	enemy.setPosition(enemyPosition);
}
