#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Level1 {
public:
	void init();

	Enemy myEnemy;
	sf::Sprite treeSprite;
	sf::Texture treeTexture;

	sf::Vector2f render(sf::RenderWindow& m_window, sf::Sprite t_player);
	sf::Vector2f handleWallCollisions(sf::Sprite t_player);
	void update();

	void handleAI();


	static const int floorAmount = 46;
	sf::Sprite floorPieces;
	static const int wallsAmount = 14;
	sf::Sprite wallPieces;
private:



	float xCoords[floorAmount] = {0,128,256,384,512,640,768,896,1024,1152,1280,1408,1536,1664,1792,
		576,832,64,128 + 64,256 + 64,384 + 64,512 + 64,640 + 64,768 + 64,896 + 64,1024 + 64,1152 + 64,1280 + 64,1408 + 
		64,1536 + 64,1664 + 64,960,1088,0,320,576,1600,1728,1344,832,960,1088,1344,1472,704,1792};

	float yCoords[floorAmount] = {1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024
		,896,768,0,0,0,0,0,0,0,0,0,0,0,0,0,0,768,768,576,576,640,640,640,704,512,384,384,256,256,256,320};

	float wallXCoords[wallsAmount] = {0,0,0,0,0,0,1856,1856,1856,1856,1856,1856 };
	float wallYCoords[wallsAmount] = {1024,896,768,384,256,128,1024,896,768,640,512,128};
	
	sf::Texture floorTexture;
};