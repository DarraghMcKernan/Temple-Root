#include "Level1.h"

void Level1::init()
{
	if (!floorTexture.loadFromFile("ASSETS/IMAGES/FloorTile.png"))
	{}
	floorPieces.setTexture(floorTexture);
	floorPieces.setScale(2, 2);
}

sf::Vector2f Level1::render(sf::RenderWindow& m_window, sf::Sprite t_player)
{
	for (int index = 0; index < floorAmount; index++)
	{
		floorPieces.setPosition(xCoords[index], yCoords[index]);
		m_window.draw(floorPieces);
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

void Level1::update()
{

}

void Level1::handleAI()
{
}