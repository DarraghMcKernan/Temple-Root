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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&currentlyJumping == false)
	{
		currentlyJumping = true;
		velocityY = -maxJumpVelocity;
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
}

void Player::jump()
{
	velocityY = velocityY + gravity;
	PlayerPos.y += velocityY;
	gravity = 0.6;
	if (velocityY > maxJumpVelocity)
	{
		currentlyJumping = false;
	}
}

void Player::update()
{
	if (currentlyJumping == true) {
		jump();
	}

	PlayerSprite.setPosition(PlayerPos);
}