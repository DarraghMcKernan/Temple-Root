#include "Game.h"

Game::Game()
	: m_window(sf::VideoMode(1920,1080,32), "Temple Root", sf::Style::Default)
{
	init();
}

void Game::run()
{
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Clock clock;
	clock.restart();



	while (m_window.isOpen())
	{
		//m_window.clear(sf::Color::White);
		sf::Event event;

		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		timeSinceLastUpdate += clock.restart();

		if (timeSinceLastUpdate > timePerFrame)
		{
			m_window.display();

			timeSinceLastUpdate = sf::Time::Zero;
		}
		render();
		update();
	}
}

void Game::init()
{
	myPlayer.init();
}

void Game::update()
{
	myPlayer.handleInput();
}

void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(myPlayer.PlayerSprite);
}
