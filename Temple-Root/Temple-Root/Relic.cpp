#include "Relic.h"

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
	relicPos.x = rand() % 1920;
	relicPos.y = rand() % 1080;
}
