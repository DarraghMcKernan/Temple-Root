#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
public:
	sf::Sprite PlayerSprite;

	void handleInput();
	void init();
	void update();
private:

	void jump();

	bool currentlyJumping = false;

	float velocityX = 0;
	float velocityY = 0;
	float gravity = 0.3;

	const int maxJumpVelocity = 20;


	sf::Texture PlayerTexture;
	sf::Vector2f PlayerPos = {500,500};

	float XSpeed = 5.0f;
};