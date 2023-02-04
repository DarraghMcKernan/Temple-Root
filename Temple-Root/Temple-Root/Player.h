#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Relic.h"
#include "Enemy.h"
#include "Button.h"

class Player {
public:
	sf::Sprite PlayerSprite;

	void handleInput();
	void init();
	void update();
	void render(sf::RenderWindow& m_window);
	void snapRelicToHand();
	void enemyCollisions();
	void keepPlayerOnBlock(float t_blockXPos);
	void hitWalls(float t_blockXPos);
	bool playerIsAttacking();

private:
	int runningAnimations = false;
	int idleAnimations = true;
	bool attackAnimation = false;

	int attackTimer = 10;
	int attackCurrentFrame = 0;
	int maxAttackAnimation = 6;

	sf::Font pixelFont;
	sf::Text timeLeft;
	
	int levelCountdown;

	bool currentlyOnBlock = false;

	int jumpCounter = 10;

	bool left = true;

	int lives = 3;
	//hearts
	sf::Texture heartTexture;
	sf::Sprite heartSprite;
	void playerHearts();
	int healthLossTimer = 120;

	Relic timeRelic;
	Enemy firstEnemy;
	Button button1;

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
	sf::Vector2f PlayerPos = {48,500};

	float XSpeed = 5.0f;
};