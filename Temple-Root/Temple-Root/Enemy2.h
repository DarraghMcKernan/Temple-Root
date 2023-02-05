#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy2 {
public:
	sf::Sprite EnemySprite2;
	// temp
	sf::RectangleShape enemy;
	void init();

	void movement(int t_min, int t_max, int t_yPos);

	void update();

	void render(sf::RenderWindow& m_window);

	bool enemyIsAlive = true;

	sf::Texture EnemyTexture2;

private:
	sf::Vector2f enemyPosition2{ 220,1000 };
	
	bool backwards = false;

	int animationTimer2 = 0;
	int animationMaxSpeed2 = 10;
	int animationCurrentFrame2 = 0;
	int animationMaxFrame2 = 8;
	bool runningAnimations2 = true;

};
