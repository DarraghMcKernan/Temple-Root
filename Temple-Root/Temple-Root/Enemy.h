#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy {
public:
	sf::Sprite EnemySprite;
	// temp
	sf::RectangleShape enemy;
	void init();
	void movement();
	void update();

	bool enemyIsAlive = true;

private:
	sf::Vector2f enemyPosition {900,1000};
	sf::Texture EnemyTexture;
	sf::Texture DeadEnemyTexture;
	bool backwards = false;

	int animationTimer = 0;
	int animationMaxSpeed = 10;
	int animationCurrentFrame = 0;
	int animationMaxFrame = 4;
	bool runningAnimations = true;

};