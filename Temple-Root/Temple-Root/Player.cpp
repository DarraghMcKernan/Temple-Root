#include "Player.h"

void Player::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		PlayerPos.x += XSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		PlayerPos.x -= XSpeed;
	}
	PlayerSprite.setPosition(PlayerPos.x,PlayerPos.y);
}

void Player::init()
{
	if (!PlayerTexture.loadFromFile("ASSETS/IMAGES/red.png"))
	{
	}
	PlayerSprite.setTexture(PlayerTexture);
	PlayerSprite.setScale(0.25, 0.25);
	PlayerSprite.setPosition(PlayerPos);
}