#include "Player.h"

void Player::handleInput()
{
	idleAnimations = true;
	runningAnimations = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20)
	{
		left = false;
		PlayerPos.x += XSpeed;
		PlayerSprite.setScale(3, 3);
		runningAnimations = true;
		idleAnimations = false;
		if (PlayerPos.x >= 1912)
		{
			PlayerPos.x = 1912;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20)
	{
		left = true;
		PlayerPos.x -= XSpeed;
		PlayerSprite.setScale(-3, 3);
		runningAnimations = true;
		idleAnimations = false;
		if (PlayerPos.x <= 8)
		{
			PlayerPos.x = 8;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && currentlyJumping == false)
	{
		currentlyJumping = true;
		velocityY = -maxJumpVelocity;
	}
	if (sf::Joystick::isButtonPressed(0, 0) && currentlyJumping == false)
	{
		currentlyJumping = true;
		velocityY = -maxJumpVelocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) || (sf::Joystick::getAxisPosition(0,sf::Joystick::Z) < -50))
	{
		attackAnimation = true;
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
	button1.init();
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
	if (velocityY > 0.01)
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
	if (attackAnimation == true)
	{
		
		attackTimer++;
		if (attackTimer >= animationMaxSpeed)
		{
			animationTimer = 0;
			attackCurrentFrame++;
			if (attackCurrentFrame >= maxAttackAnimation)
			{
				attackCurrentFrame = 0;
				attackAnimation = false;
			}
		}
		PlayerSprite.setTextureRect(sf::IntRect((64 * attackCurrentFrame), 96, 36, 22));
	}
}

void Player::update()
{
	if (currentlyJumping == true) {
		jump();
	}
	if (currentlyJumping == false)
	{
		PlayerPos.y += 10;
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
	if (firstEnemy.enemyIsAlive == true)
	{
		
		firstEnemy.movement(850, 1200, 750);
	}
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
	button1.render(m_window);
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
	if (PlayerSprite.getGlobalBounds().intersects(firstEnemy.EnemySprite.getGlobalBounds()) && firstEnemy.enemyIsAlive == true && !playerIsAttacking())
	{
		if (healthLossTimer <= 0)
		{
			lives--;
			healthLossTimer = 120;
		}
	}
	if (PlayerSprite.getGlobalBounds().intersects(firstEnemy.EnemySprite.getGlobalBounds()) && playerIsAttacking())
	{
		firstEnemy.enemyIsAlive = false;
		lives++;
	}
	if (PlayerSprite.getGlobalBounds().intersects(button1.button.getGlobalBounds()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		timeRelic.randomPos();
	}
}
void Player::keepPlayerOnBlock(float t_blockYPos)
{
	if (currentlyJumping == true)
	{
		PlayerPos.y = t_blockYPos + 64;
	}
	else{

		PlayerPos.y = t_blockYPos - 64;
	}
	currentlyJumping = false;

	PlayerSprite.setPosition(PlayerPos.x, PlayerPos.y);
	
}

void Player::hitWalls(float t_blockXPos)
{
	if (left == true)
	{
		PlayerPos.x = t_blockXPos+84;
	}
	else PlayerPos.x = t_blockXPos -24;
	PlayerSprite.setPosition(PlayerPos);
}
bool Player::playerIsAttacking()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		return true;
	}
	return false;
}

