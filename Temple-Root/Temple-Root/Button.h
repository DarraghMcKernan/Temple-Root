#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
	void init();
	void update();
	void render(sf::RenderWindow& m_window);
	sf::CircleShape button;
	sf::Texture buttonTexture;
	sf::Sprite buttonSprite;
private:
	

	sf::Vector2f buttonPos{ 200,960 };

};
