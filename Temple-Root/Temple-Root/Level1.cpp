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

	if(!treeTexture.loadFromFile("ASSETS/IMAGES/tree.png"))
	{ }
	treeSprite.setTexture(treeTexture);
	treeSprite.setPosition(1800, 100);
	//treeSprite.setScale(2, 2);
	//myEnemy.init();
}

sf::Vector2f Level1::render(sf::RenderWindow& m_window, sf::Sprite t_player)
{
	//m_window.draw(myEnemy.EnemySprite);
	//m_window.draw(treeSprite);
	for (int index = 0; index < floorAmount; index++)//keep looping until all floors have had their positions set from the array of coordinates
	{
		floorPieces.setPosition(xCoords[index], yCoords[index]);//place floor
		m_window.draw(floorPieces);//draw floor - this allows 1 single sprite to be in several places at 1 time
	}
	for (int index = 0; index < wallsAmount; index++)//same as floors but walls required a new type of collisions and so needed a new sprite
	{
		wallPieces.setPosition(wallXCoords[index], wallYCoords[index]);
		m_window.draw(wallPieces);
	}
	for (int index = 0; index < floorAmount; index++)
	{
		floorPieces.setPosition(xCoords[index], yCoords[index]);
		if (t_player.getGlobalBounds().intersects(floorPieces.getGlobalBounds()))//used for the brain melting collisions
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
		wallPieces.setPosition(wallXCoords[index], wallYCoords[index]);//place the walls then check for collisons 
		if (t_player.getGlobalBounds().intersects(wallPieces.getGlobalBounds()))
		{
			return sf::Vector2f(wallXCoords[index], wallYCoords[index]);//send back coords of the wall that has collided
		}
	}

	return {0,0};
}

void Level1::update()
{
	//myEnemy.update();
	handleAI();
}

void Level1::handleAI()
{
	//myEnemy.movement(850,1200,750);
}