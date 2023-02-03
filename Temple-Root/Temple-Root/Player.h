#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
public:
	sf::Sprite PlayerSprite;

	void handleInput();
	void init();
private:


	sf::Texture PlayerTexture;
	sf::Vector2f PlayerPos = {500,500};

	float XSpeed = 1.0f;
};