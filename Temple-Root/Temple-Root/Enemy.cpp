#include "Enemy.h"

void Enemy::init()
{
	if (!EnemyTexture.loadFromFile("ASSETS/IMAGES/enemy-Sheet.png"))
	{
		std::cout << "problem loading texture";
	}
	EnemySprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	EnemySprite.setTexture(EnemyTexture);
	EnemySprite.setScale(3,3);
	EnemySprite.setPosition(enemyPosition);
}

void Enemy::movement()
{
	if (enemyPosition.x >= 100 && enemyPosition.x <= 200 && backwards == false)
	{
		enemyPosition.x++;
		EnemySprite.setScale(-3, 3);

		if (enemyPosition.x >= 200)
		{
			backwards = true;
		}
	}
	if (enemyPosition.x >= 100 && enemyPosition.x <= 200 && backwards == true)
	{
		enemyPosition.x--;
		EnemySprite.setScale(3, 3);
		if (enemyPosition.x <= 100)
		{
			backwards = false;
		}
	}
	EnemySprite.setPosition(enemyPosition);
}

void Enemy::update()
{
	animationTimer++;
	if (animationTimer >= animationMaxSpeed)
	{
		animationTimer = 0;
		animationCurrentFrame++;
		if (animationCurrentFrame >= animationMaxFrame)
		{
			animationCurrentFrame = 0;
		}
		if (runningAnimations == true)
		{
			EnemySprite.setTextureRect(sf::IntRect((16 * animationCurrentFrame), 0, 16, 16));//16 22
		}
	
	}
	EnemySprite.setPosition(enemyPosition);
}
