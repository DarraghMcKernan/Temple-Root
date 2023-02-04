#include "Game.h"

Game::Game()
	: m_window(sf::VideoMode(1920,1080,32), "Temple Root", sf::Style::Default)//screen width, screen height, bits per pixel, Name at top of Window
{
	init();// sets up all variables and objects
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame); //60 fps
			render(); // as many as possible
			if (m_exitGame == true)
			{
				m_window.close();
			}
		}
	}
}

void Game::init()
{
	myPlayer.init();
}

void Game::update(sf::Time t_deltaTime)
{
	myPlayer.handleInput();//used for player movement
	myPlayer.update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_exitGame = true;//closes the game
	}
}

void Game::render()
{
	m_window.clear(sf::Color::White);//clears the screen and sets a background colour
	m_window.draw(myPlayer.PlayerSprite);
	m_window.display();//shows evrything on screen (important)
}
