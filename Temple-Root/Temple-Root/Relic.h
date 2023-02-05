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
	void randomPos();
private:
	int animationTimer = 0;
	int animationMaxSpeed = 10;
	int animationCurrentFrame = 0;
	int animationMaxFrame = 7;
	sf::Vector2f rand1{ 200,200 };
	sf::Vector2f rand2{ 700,500 };
	sf::Vector2f rand3{ 900,900 };
	sf::Vector2f rand4{ 1500,500 };
	sf::Vector2f rand5{ 1200,300 };
	sf::Vector2f rand6{ 400,800 };
	const int SPRITE_SIZE = 16;
	
};
