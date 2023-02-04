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

private:
	sf::Vector2f enemyPosition {100,100};
	sf::Texture EnemyTexture;
	bool backwards = false;

};