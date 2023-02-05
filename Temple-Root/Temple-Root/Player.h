#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Relic.h"
#include "Enemy.h"
#include "Button.h"
#include "Enemy2.h"

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
	sf::Text retry;
	int greyOut = 0;
	sf::RectangleShape endScreen;
	int levelCountdown;
	int maxTime = 3600;

	bool dead = false;

	bool currentlyOnBlock = false;

	bool holdingRelic = false;

	int jumpCounter = 10;

	bool left = true;

	bool winState = false;

	sf::Text winMessage;

	int lives = 3;
	//hearts
	sf::Texture heartTexture;
	sf::Sprite heartSprite;
	void playerHearts();
	int healthLossTimer = 120;

	int relicTimer = 120;

	sf::Sprite pedestal;
	sf::Texture pedestalTexture;

	Relic timeRelic;
	Enemy firstEnemy;
	Button button1;
	Button button2;
	Button button3;
	Enemy2 secondEnemy;

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
	sf::Vector2f PlayerPos = { 24,500 };
	sf::Vector2f spawnPos = { 24,500 };

	float XSpeed = 5.0f;
};