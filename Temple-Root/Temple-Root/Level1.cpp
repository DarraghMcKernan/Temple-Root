#include "Level1.h"

void Level1::init()
{
	if (!floorTexture.loadFromFile("ASSETS/IMAGES/FloorTile.png"))
	{}
	floorPieces.setTexture(floorTexture);
	floorPieces.setScale(2, 2);
}

void Level1::render(sf::RenderWindow& m_window)
{
	for (int index = 0; index < floorAmount; index++)
	{
		floorPieces.setPosition(xCoords[index], yCoords[index]);
		m_window.draw(floorPieces);
	}
}

void Level1::update()
{

}

void Level1::handleAI()
{
}