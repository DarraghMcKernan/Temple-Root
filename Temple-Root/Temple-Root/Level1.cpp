#include "Level1.h"

void Level1::init()
{
	if (!floorTexture.loadFromFile("ASSETS/IMAGES/FloorTile.png"))
	{}
	floorPieces.setTexture(floorTexture);
	floorPieces.setScale(2, 2);
	wallPieces.setTexture(floorTexture);
	wallPieces.setScale(2, 2);
	wallPieces.rotate(-90);
}

sf::Vector2f Level1::render(sf::RenderWindow& m_window, sf::Sprite t_player)
{
	for (int index = 0; index < floorAmount; index++)
	{
		floorPieces.setPosition(xCoords[index], yCoords[index]);
		m_window.draw(floorPieces);
	}
	for (int index = 0; index < wallsAmount; index++)
	{
		wallPieces.setPosition(wallXCoords[index], wallYCoords[index]);
		m_window.draw(wallPieces);
	}
	for (int index = 0; index < floorAmount; index++)
	{
		floorPieces.setPosition(xCoords[index], yCoords[index]);
		if (t_player.getGlobalBounds().intersects(floorPieces.getGlobalBounds()))
		{
			return sf::Vector2f(xCoords[index], yCoords[index]);
		}
	}
	return { 0,0 };
}

sf::Vector2f Level1::handleWallCollisions(sf::Sprite t_player)
{
	for (int index = 0; index < wallsAmount; index++)
	{
		wallPieces.setPosition(wallXCoords[index], wallYCoords[index]);
		if (t_player.getGlobalBounds().intersects(wallPieces.getGlobalBounds()))
		{
			return sf::Vector2f(wallXCoords[index], wallYCoords[index]);
		}
	}

	return {0,0};
}

void Level1::update()
{

}

void Level1::handleAI()
{
}