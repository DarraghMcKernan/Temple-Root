#pragma once
#include <SFML/Graphics.hpp>

class Level1 {
public:
	void init();

	sf::Vector2f render(sf::RenderWindow& m_window, sf::Sprite t_player);

	void update();

	void handleAI();


	static const int floorAmount = 5;
	sf::Sprite floorPieces;
private:



	float xCoords[floorAmount] = {0,128,256,384,512};
	float yCoords[floorAmount] = {1024,1024,1024,1024,1024 };
	
	sf::Texture floorTexture;
};