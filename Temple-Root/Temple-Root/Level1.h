#pragma once
#include <SFML/Graphics.hpp>

class Level1 {
public:
	void init();

	sf::Vector2f render(sf::RenderWindow& m_window, sf::Sprite t_player);
	sf::Vector2f handleWallCollisions(sf::Sprite t_player);
	void update();

	void handleAI();


	static const int floorAmount = 31;
	sf::Sprite floorPieces;
	static const int wallsAmount = 16;
	sf::Sprite wallPieces;
private:



	float xCoords[floorAmount] = {0,128,256,384,512,640,768,896,1024,1152,1280,1408,1536,1664,1792,576,832,64,128 + 64,256 + 64,384 + 64,512 + 64,640 + 64,768 + 64,896 + 64,1024 + 64,1152 + 64,1280 + 64,1408 + 64,1536 + 64,1664 + 64};
	float yCoords[floorAmount] = {1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,896,768,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	float wallXCoords[wallsAmount] = {0,0,0,0,0,0,0,0,1856,1856,1856,1856,1856,1856,1856,1856 };
	float wallYCoords[wallsAmount] = {1024,896,768,640,512,384,256,128,1024,896,768,640,512,384,256,128};
	
	sf::Texture floorTexture;
};