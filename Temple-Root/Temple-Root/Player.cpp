#include "Player.h"

void Player::handleInput()
{
	idleAnimations = true;
	runningAnimations = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		PlayerPos.x += XSpeed;
		PlayerSprite.setScale(3, 3);
		runningAnimations = true;
		idleAnimations = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		PlayerPos.x -= XSpeed;
		PlayerSprite.setScale(-3, 3);
		runningAnimations = true;
		idleAnimations = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&currentlyJumping == false)
	{
		currentlyJumping = true;
		velocityY = -maxJumpVelocity;
	}
	PlayerSprite.setPosition(PlayerPos);
}

void Player::init()
{
	if (!PlayerTexture.loadFromFile("ASSETS/IMAGES/ArchaeologistSpriteSheet.png"))
	{
	}
	PlayerSprite.setTexture(PlayerTexture);
	PlayerSprite.setScale(0.25, 0.25);
	PlayerSprite.setPosition(PlayerPos);
	PlayerSprite.setTextureRect(sf::IntRect(0, 0, 17, 22));	//16 22
	PlayerSprite.setOrigin(8, 0);
	PlayerSprite.setScale(3, 3);
	timeRelic.init();
}

void Player::jump()
{
	velocityY = velocityY + gravity;
	PlayerPos.y += velocityY;
	gravity = 0.6;
	if (velocityY >= maxJumpVelocity)
	{
		currentlyJumping = false;
	}
}

void Player::handleAnimations()
{
	if (idleAnimations == true)
	{
		PlayerSprite.setTextureRect(sf::IntRect((64 * animationCurrentFrame), 0, 17, 22));//16 22
	}
	if (runningAnimations == true)
	{
		PlayerSprite.setTextureRect(sf::IntRect((64 * animationCurrentFrame), 29, 18, 25));//16 22
	}
}

void Player::update()
{
	if (currentlyJumping == true) {
		jump();
	}
	animationTimer++;
	if (animationTimer >= animationMaxSpeed)
	{
		animationTimer = 0;
		animationCurrentFrame++;
		if (animationCurrentFrame >= animationMaxFrame)
		{
			animationCurrentFrame = 0;
		}
		handleAnimations();
	}
	timeRelic.update();
	snapRelicToHand();

	PlayerSprite.setPosition(PlayerPos);
}

void Player::render(sf::RenderWindow& m_window)
{
	m_window.draw(PlayerSprite);
	timeRelic.render(m_window);
}

void Player::snapRelicToHand()
{
	if (PlayerSprite.getGlobalBounds().intersects(timeRelic.relicSprite.getGlobalBounds()))
	{
		/*timeRelic.relicPos.x = PlayerPos.x += 20;
		timeRelic.relicPos.y = PlayerPos.y;*/
		timeRelic.relicPos = PlayerPos;
	}
}
