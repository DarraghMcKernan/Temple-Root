#pragma once
#include <SFML/Graphics.hpp>

class Level1 {
public:
	void init();

	sf::Vector2f render(sf::RenderWindow& m_window, sf::Sprite t_player);

	void update();

	void handleAI();


	static const int floorAmount = 17;
	sf::Sprite floorPieces;
private:



	float xCoords[floorAmount] = {0,128,256,384,512,640,768,896,1024,1152,1280,1408,1536,1664,1792,576,832};
	float yCoords[floorAmount] = {1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,1024,896,768};
	
	sf::Texture floorTexture;
};