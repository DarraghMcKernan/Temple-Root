#pragma once
#include <SFML/Graphics.hpp>

class Level1 {
public:
	void init();

	void render(sf::RenderWindow& m_window);

	void update();

	void handleAI();
private:
	static const int floorAmount = 5;
	sf::Sprite floorPieces;

	float xCoords[floorAmount] = {0,128,256,384,512};
	float yCoords[floorAmount] = {1024,1024,1024,1024,1024 };
	
	sf::Texture floorTexture;
};