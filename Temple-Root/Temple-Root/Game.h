#pragma once
//includes for game
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Relic.h"
#include "Enemy.h"


class Game {
public: 
	Game();
	void run();
private:
	void processEvents();
	void processKeys(sf::Event t_event);
	void init();
	void update(sf::Time t_deltaTime);
	void render();

	Player myPlayer;
	Enemy firstEnemy;
	bool m_exitGame = false;

	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	//render window 
	sf::RenderWindow m_window;
};
