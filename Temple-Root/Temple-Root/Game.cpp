#include "Game.h"

Game::Game()
	: m_window(sf::VideoMode(1920,1080,32), "Temple Root", sf::Style::Fullscreen)//screen width, screen height, bits per pixel, Name at top of Window
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
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

void Game::init()
{
	myPlayer.init();
	firstLevel.init();
	if(!bgMusic.openFromFile("ASSETS/AUDIO/music.ogg"))
	{ }
	bgMusic.play();
	bgMusic.setLoop(true);
	bgMusic.setVolume(100.0f);

	if(!backgroundTexture.loadFromFile("ASSETS/IMAGES/StoneTiles.png"))
	{ }
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(2, 2);
	backgroundSprite.setColor(sf::Color(130, 130, 130));
}

void Game::update(sf::Time t_deltaTime)
{
	myPlayer.handleInput();//used for player movement
	sf::Vector2f wallHit = firstLevel.handleWallCollisions(myPlayer.PlayerSprite);
	if (wallHit != sf::Vector2f(0, 0))
	{
		myPlayer.hitWalls(wallHit.x);
	}
	myPlayer.update();
	firstLevel.update();
	if (m_exitGame)
	{
		m_window.close();
	}

}

void Game::render()
{
	m_window.clear(sf::Color::White);//clears the screen and sets a background colour
	m_window.draw(backgroundSprite);
	m_window.draw(myPlayer.treeSprite);
	sf::Vector2f playerStandHere = firstLevel.render(m_window,myPlayer.PlayerSprite);
	if (playerStandHere != sf::Vector2f(0, 0))
	{
		myPlayer.keepPlayerOnBlock(playerStandHere.y);
	}
	myPlayer.render(m_window);
	m_window.display();//shows evrything on screen (important)
}
