#pragma once
//includes for game
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Relic.h"
#include "Enemy.h"
#include "Level1.h"
#include <SFML/Audio.hpp>




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

	sf::Music bgMusic;

	Player myPlayer;
	Level1 firstLevel;
	bool m_exitGame = false;

	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	//render window 
	sf::RenderWindow m_window;
	

};
