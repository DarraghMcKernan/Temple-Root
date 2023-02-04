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

	void handleAnimations();

	bool currentlyJumping = false;

	float velocityX = 0;
	float velocityY = 0;
	float gravity = 0.3;

	const int maxJumpVelocity = 15;

	int spaceBetweenSpritesSide = 48;

	int animationTimer = 0;
	int animationMaxSpeed = 10;
	int animationCurrentFrame = 0;
	int animationMaxFrame = 8;

	sf::Texture PlayerTexture;
	sf::Vector2f PlayerPos = {500,500};

	float XSpeed = 5.0f;
};