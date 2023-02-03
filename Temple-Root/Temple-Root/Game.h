#pragma once
//includes for game
#include <SFML/Graphics.hpp>
#include <iostream>


class Game {
public: 
	Game();
	void run();
private:
	void init();
	void update(double dt);
	void render();

	//render window 
	sf::RenderWindow m_window;
};
