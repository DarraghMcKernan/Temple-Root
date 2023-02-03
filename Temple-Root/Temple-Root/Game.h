#pragma once
//includes for game
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"


class Game {
public: 
	Game();
	void run();
private:
	void init();
	void update();
	void render();

	Player myPlayer;

	//render window 
	sf::RenderWindow m_window;
};
