#include "Enemy2.h"

void Enemy2::init()
{
	if (!EnemyTexture2.loadFromFile("ASSETS/IMAGES/spikeEnemy-Sheet.png"))
	{
		std::cout << "problem loading texture";
	}
	if (!DeadEnemy2.loadFromFile("ASSETS/IMAGES/spike-enemy-dead.png"))
	{
		std::cout << "problem loading texture";
	}
	EnemySprite2.setTextureRect(sf::IntRect(0, 0, 16, 16));
	EnemySprite2.setTexture(EnemyTexture2);
	EnemySprite2.setScale(3, 3);
	EnemySprite2.setOrigin(8, 8);
	EnemySprite2.setPosition(enemyPosition2);
}

void Enemy2::movement(int t_min, int t_max, int t_yPos)
{
	if (enemyPosition2.x >= t_min && enemyPosition2.x <= t_max && backwards == false)
	{
		enemyPosition2.x++;
		EnemySprite2.setScale(-3, 3);

		if (enemyPosition2.x >= t_max)
		{
			backwards = true;
		}
	}
	if (enemyPosition2.x >= t_min && enemyPosition2.x <= t_max && backwards == true)
	{
		enemyPosition2.x--;
		EnemySprite2.setScale(3, 3);
		if (enemyPosition2.x <= t_min)
		{
			backwards = false;
		}
	}

	enemyPosition2.y = t_yPos;
	EnemySprite2.setPosition(enemyPosition2);

	
}

void Enemy2::update()
{
	animationTimer2++;
	if (animationTimer2 >= animationMaxSpeed2)
	{
		animationTimer2 = 0;
		animationCurrentFrame2++;
		if (animationCurrentFrame2 >= animationMaxFrame2)
		{
			animationCurrentFrame2 = 0;
		}
		if (runningAnimations2 == true)
		{
			EnemySprite2.setTextureRect(sf::IntRect((16 * animationCurrentFrame2), 0, 16, 16));//16 22
		}

	}
	//EnemySprite2.setPosition(enemyPosition2);
	if (enemyIsAlive == false)
	{
		EnemySprite2.setTexture(DeadEnemy2);
		EnemySprite2.setTextureRect(sf::IntRect(0, 0, 16, 16));
	}
	else {
	}
}

void Enemy2::render(sf::RenderWindow& m_window)
{
	m_window.draw(EnemySprite2);
}
