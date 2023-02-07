#include "Relic.h"
#include <cstdlib>//needed for srand
#include <ctime>//needed for srand

void Relic::init()
{
	/*relicTemp.setSize(sf::Vector2f(30, 30));
	relicTemp.setOrigin(sf::Vector2f(15, 25));
	relicTemp.setPosition(relicPos);
	relicTemp.setFillColor(sf::Color::Red);*/
	if (!relicTexture.loadFromFile("ASSETS/IMAGES/Relic.png"))
	{
		std::cout << "error loading relic spritesheet" << "\n";
	}
	relicSprite.setTexture(relicTexture);
	relicSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	relicSprite.setOrigin(8, 12);
	relicSprite.setScale(2, 2);
	relicSprite.setPosition(relicPos);
}

void Relic::update()
{
	relicSprite.setPosition(relicPos);
	handleAnimation();
}

void Relic::render(sf::RenderWindow& m_window)
{
	m_window.draw(relicSprite);
}

void Relic::handleAnimation()
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
		relicSprite.setTextureRect(sf::IntRect((16 * animationCurrentFrame), 0, 16, 16));//16 22
	}
}

void Relic::randomPos()
{
	srand((unsigned)time(NULL));//used for time based random numbers - the easiest and best way to get truly 'random' numbers
	int random = (rand() % 6) + 1;//get a random number
	if (random == 1)//pick from preset coords
	{
		relicPos = rand1;
	}
	else if (random == 2)
	{
		relicPos = rand2;
	}
	else if (random == 3)
	{
		relicPos = rand3;
	}
	else if (random == 4)
	{
		relicPos = rand4;
	}
	else if (random == 5)
	{
		relicPos = rand5;
	}
	else if (random == 6)
	{
		relicPos = rand6;
	}
	
}
