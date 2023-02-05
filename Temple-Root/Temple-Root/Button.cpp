#include "Button.h"

void Button::init()
{
	button.setRadius(20U);
	button.setFillColor(sf::Color::Red);
	button.setOrigin(10, 10);
	button.setPosition(buttonPos);

	if (!buttonTexture.loadFromFile("ASSETS/IMAGES/button-sheet.png"))
	{
		std::cout << "error loading buttons" << "\n";
	}
}

void Button::update()
{

}

void Button::render(sf::RenderWindow & m_window)
{
	m_window.draw(button);
}
