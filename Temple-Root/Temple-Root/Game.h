#pragma once
//includes for game
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Relic.h"


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

	bool m_exitGame = false;


	//render window 
	sf::RenderWindow m_window;
};
