#include "Button.h"

void Button::init()
{
	/*button.setRadius(20U);
	button.setFillColor(sf::Color::Red);
	button.setOrigin(10, 10);
	button.setPosition(buttonPos);*/

	if (!buttonTexture.loadFromFile("ASSETS/IMAGES/button-sheet.png"))
	{
		std::cout << "error loading buttons" << "\n";
	}
	if (!greenTexture.loadFromFile("ASSETS/IMAGES/button-green.png"))
	{
		std::cout << "error loading green button" << "\n";
	}
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setOrigin(8, 8);
	buttonSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	buttonSprite.setPosition(buttonPos);
	buttonSprite.setScale(2.5, 2.5);
}

void Button::update()
{
	if (isAnimating == true)
	{
		animationTimer++;
		if (animationTimer >= animationMaxSpeed)//used to have a set amount of frames between different animations being played
		{
			animationTimer = 0;
			animationCurrentFrame++;//used to move to next frame in spritesheet
			if (animationCurrentFrame >= animationMaxFrame)//if you get to the end of the spritesheet
			{
				animationCurrentFrame = 0;
				isAnimating = false;
				buttonSprite.setTexture(greenTexture);
				buttonSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
			}
			buttonSprite.setTextureRect(sf::IntRect((16 * animationCurrentFrame), 0, 16, 16));//X coord in spritesheet, Y coord in spritesheet, x width of image, y height of iamge
		}
	}
	
}

void Button::render(sf::RenderWindow & m_window)
{
	m_window.draw(buttonSprite);
}
