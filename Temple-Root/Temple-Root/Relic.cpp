#include "Relic.h"

void Relic::init()
{
	relicTemp.setSize(sf::Vector2f(30, 30));
	relicTemp.setOrigin(sf::Vector2f(15, 25));
	relicTemp.setPosition(relicPos);
	relicTemp.setFillColor(sf::Color::Red);
}

void Relic::update()
{
	relicTemp.setPosition(relicPos);
}

void Relic::render(sf::RenderWindow& m_window)
{
	m_window.draw(relicTemp);
}
