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

private:
	sf::Vector2f enemyPosition {900,500};
	sf::Texture EnemyTexture;
	bool backwards = false;

	int animationTimer = 0;
	int animationMaxSpeed = 10;
	int animationCurrentFrame = 0;
	int animationMaxFrame = 4;
	bool runningAnimations = true;

};