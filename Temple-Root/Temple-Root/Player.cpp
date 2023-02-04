#include "Player.h"

void Player::handleInput()
{
	idleAnimations = true;
	runningAnimations = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		PlayerPos.x += XSpeed;
		PlayerSprite.setScale(3, 3);
		runningAnimations = true;
		idleAnimations = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
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

	// heart
	if (!heartTexture.loadFromFile("ASSETS/IMAGES/heart-spritesheet.png"))
	{
		std::cout << "error loading hearts" << "\n";
	}
	heartSprite.setTexture(heartTexture);
	heartSprite.setTextureRect(sf::IntRect(0, 0, 48, 16));
	heartSprite.setScale(5, 5);
	timeRelic.init();
	firstEnemy.init();
}

void Player::playerHearts()
{
	if (lives == 2)
	{
		heartSprite.setTextureRect(sf::IntRect(0, 0, 32, 16));
	}
	else if (lives == 1)
	{
		heartSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	}
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
	if (currentlyJumping == true)
	{
		PlayerSprite.setTextureRect(sf::IntRect(130, 30, 18, 25));
	}
}

void Player::update()
{
	if (currentlyJumping == true) {
		jump();
	}
	if (currentlyJumping == false)
	{
		PlayerPos.y += 15;
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
	healthLossTimer--;
	timeRelic.update();
	snapRelicToHand();
	firstEnemy.update();
	enemyCollisions();
	playerHearts();
	

	PlayerSprite.setPosition(PlayerPos);
}

void Player::render(sf::RenderWindow& m_window)
{
	m_window.draw(PlayerSprite);
	timeRelic.render(m_window);
	m_window.draw(firstEnemy.EnemySprite);
	m_window.draw(heartSprite);
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

void Player::enemyCollisions()
{
	if (PlayerSprite.getGlobalBounds().intersects(firstEnemy.EnemySprite.getGlobalBounds()) && enemyIsAlive == true)
	{
		if (healthLossTimer <= 0)
		{
			lives--;
			healthLossTimer = 120;
		}
	}
	if (PlayerSprite.getGlobalBounds().intersects(firstEnemy.EnemySprite.getGlobalBounds()) && playerIsAttacking())
	{
		enemyIsAlive = false;
	}
}
void Player::keepPlayerOnBlock(float t_blockXPos)
{
	PlayerPos.y = t_blockXPos-64;
	PlayerSprite.setPosition(PlayerPos.x, PlayerPos.y);
}

bool Player::playerIsAttacking()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		return true;
	}
	return false;
}

