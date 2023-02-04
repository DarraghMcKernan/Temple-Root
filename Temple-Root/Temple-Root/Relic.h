#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Relic {
public:
	void init();
	void update();
	void render(sf::RenderWindow& m_window);
	void handleAnimation();
	sf::RectangleShape relicTemp;
	sf::Texture relicTexture;
	sf::Sprite relicSprite;
	sf::Vector2f relicPos{ 700,500 };
private:
	int animationTimer = 0;
	int animationMaxSpeed = 10;
	int animationCurrentFrame = 0;
	int animationMaxFrame = 7;
	const int SPRITE_SIZE = 16;
	
};
