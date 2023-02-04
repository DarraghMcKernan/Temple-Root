#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Relic {
public:
	void init();
	void update();
	void render(sf::RenderWindow& m_window);
	sf::RectangleShape relicTemp;
	sf::Vector2f relicPos{ 700,500 };
private:
	
	
};
