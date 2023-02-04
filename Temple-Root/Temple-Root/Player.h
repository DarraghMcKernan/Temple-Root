#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Relic.h"

class Player {
public:
	sf::Sprite PlayerSprite;

	void handleInput();
	void init();
	void update();
	void render(sf::RenderWindow& m_window);
	void snapRelicToHand();
	void keepPlayerOnBlock(float t_blockXPos);
private:
	int runningAnimations = false;
	int idleAnimations = true;

	Relic timeRelic;

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
	int animationMaxFrame = 7;

	sf::Texture PlayerTexture;
	sf::Vector2f PlayerPos = {500,100};

	float XSpeed = 5.0f;
};