#include "Enemy.h"

void Enemy::init()
{
	if (!EnemyTexture.loadFromFile("ASSETS/IMAGES/enemy-Sheet.png"))
	{
		std::cout << "problem loading texture";
	}
	if (!DeadEnemyTexture.loadFromFile("ASSETS/IMAGES/dead-worm.png"))
	{
		std::cout << "problem loading texture";
	}
	EnemySprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	EnemySprite.setTexture(EnemyTexture);
	EnemySprite.setScale(3,3);
	EnemySprite.setOrigin(8, 8);
	EnemySprite.setPosition(enemyPosition);
}

void Enemy::movement(int t_min, int t_max,int t_yPos)
{
	if (enemyPosition.x >= t_min && enemyPosition.x <= t_max && backwards == false)
	{
		enemyPosition.x++;
		EnemySprite.setScale(-3, 3);

		if (enemyPosition.x >= t_max)
		{
			backwards = true;
		}
	}
	if (enemyPosition.x >= t_min && enemyPosition.x <= t_max && backwards == true)
	{
		enemyPosition.x--;
		EnemySprite.setScale(3, 3);
		if (enemyPosition.x <= t_min)
		{
			backwards = false;
		}
	}
	enemyPosition.y = t_yPos;
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

	if (enemyIsAlive == false)
	{
		EnemySprite.setTexture(DeadEnemyTexture);
		EnemySprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	}
	else {
		//movement(850,1200,750);
	}
}
