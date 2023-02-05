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
	sf::Texture greenTexture;
	sf::Sprite buttonSprite;
	bool isAnimating = false;
	bool buttonPressed = false;
private:
	int animationTimer = 0;
	int animationMaxSpeed = 10;
	int animationCurrentFrame = 0;
	int animationMaxFrame = 4;

	sf::Vector2f buttonPos{ 200,960 };

};
