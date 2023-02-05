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
		if (PlayerPos.x >= 1912 && winState == false)
		{
			PlayerPos.x = 1912;
		}
		if (PlayerPos.x > 1916)
		{
			winMessage.setString("Thank you for playing our demo : )");
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) || sf::Joystick::isButtonPressed(0, 3))
	{
		if (levelCountdown <=0)
		{
			button1.buttonPressed = false;
			button2.buttonPressed = false;
			button3.buttonPressed = false;
			button1.init();
			button2.init();
			button2.buttonSprite.setPosition(515, 200);
			button3.init();
			button3.buttonSprite.setPosition(1858, 256);

			firstEnemy.enemyIsAlive = true;

			dead = false;
			lives = 3;
			levelCountdown = maxTime;
			PlayerPos = spawnPos;
		}
	}
	if (sf::Joystick::isButtonPressed(0, 0) && currentlyJumping == false)
	{
		currentlyJumping = true;
		velocityY = -maxJumpVelocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		attackAnimation = true;
	}
	if ((sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -50))
	{
		attackAnimation = true;
	}
	PlayerSprite.setPosition(PlayerPos);
}

void Player::init()
{
	if (!PlayerTexture.loadFromFile("ASSETS/IMAGES/ArchaeologistSpriteSheet.png"))
	{
		std::cout << "error loading player\n";
	}
	PlayerSprite.setTexture(PlayerTexture);
	PlayerSprite.setScale(0.25, 0.25);
	PlayerSprite.setPosition(PlayerPos);
	PlayerSprite.setTextureRect(sf::IntRect(0, 0, 17, 22));	//16 22
	PlayerSprite.setOrigin(8, 0);
	PlayerSprite.setScale(3, 3);

	//tree 
	if (!treeTexture.loadFromFile("ASSETS/IMAGES/tree.png"))
	{
		std::cout << "error loading tree" << "\n";
	}
	treeSprite.setTexture(treeTexture);
	treeSprite.setPosition(1500, 630);
	treeSprite.setScale(2, 2);

	// heart
	if (!heartTexture.loadFromFile("ASSETS/IMAGES/heart-spritesheet.png"))
	{
		std::cout << "error loading hearts \n";
	}
	heartSprite.setTexture(heartTexture);
	heartSprite.setTextureRect(sf::IntRect(0, 0, 48, 16));
	heartSprite.setScale(5, 5);
	timeRelic.init();
	firstEnemy.init();
	secondEnemy.init();

	if(!pixelFont.loadFromFile("ASSETS/FONTS/Minecraft.ttf"))
	{
		std::cout << "error loading font\n";
	}
	timeLeft.setFont(pixelFont);
	timeLeft.setCharacterSize(50);
	timeLeft.setFillColor(sf::Color::White);
	timeLeft.setPosition(1600, 1);

	retry.setFont(pixelFont);
	retry.setCharacterSize(70);
	retry.setFillColor(sf::Color::White);
	retry.setPosition(960,400);
	retry.setString("Press Y to retry");
	retry.setOrigin(300, 0);

	winMessage.setFont(pixelFont);
	winMessage.setCharacterSize(70);
	winMessage.setFillColor(sf::Color::White);
	winMessage.setPosition(650, 500);

	winMessage.setOrigin(300, 0);

	endScreen.setSize(sf::Vector2f(1920, 1080));
	endScreen.setFillColor(sf::Color(255, 255, 255, 0));

	levelCountdown = maxTime; //3600;
	button1.init();
	button2.init();
	button2.buttonSprite.setPosition(515, 200);
	button3.init();
	button3.buttonSprite.setPosition(1858, 256);


	if(!pedestalTexture.loadFromFile("ASSETS/IMAGES/pillar.png"))
	{
		std::cout << "error loading pillar\n";
	}
	pedestal.setTexture(pedestalTexture);
	pedestal.setScale(3, 3);
	pedestal.setPosition(80, 525);
}

void Player::playerHearts()
{
	if (lives == 3)
	{
		heartSprite.setTextureRect(sf::IntRect(0, 0, 48, 16));
	}
	if (lives == 2)
	{
		heartSprite.setTextureRect(sf::IntRect(0, 0, 32, 16));
	}
	if (lives == 1)
	{
		heartSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	}
	if (lives == 0)
	{
		heartSprite.setTextureRect(sf::IntRect(0, 0, 0,16));
		if (dead == false)
		{
			dead = true;
			levelCountdown = 240;
		}
	}
}

void Player::jump()
{
	velocityY = velocityY + gravity;
	PlayerPos.y += velocityY;
	gravity = 0.6;
	if (velocityY > 0.01)
	{
		//currentlyJumping = false;
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
	relicTimer--;
	timeRelic.update();
	button1.update();
	button2.update();
	button3.update();

	if (button1.buttonPressed == true && button2.buttonPressed == true && button3.buttonPressed == true)
	{
		if (timeRelic.relicPos == sf::Vector2f(108, 515))
		{
			winState = true;
		}
	}

	snapRelicToHand();
	if (firstEnemy.enemyIsAlive == true)
	{
		firstEnemy.movement(850, 1200, 750);
	}
	if (secondEnemy.enemyIsAlive == true)
	{
		secondEnemy.movement(220, 800, 230);
	}
	firstEnemy.update();
	secondEnemy.update();
	enemyCollisions();
	playerHearts();
	levelCountdown--;
	if (levelCountdown < 0)
	{
		levelCountdown = 0;
	}
	int seconds = levelCountdown / 60;
	timeLeft.setString("Time left: "+std::to_string(seconds));
	PlayerSprite.setPosition(PlayerPos);
}

void Player::render(sf::RenderWindow& m_window)
{
	m_window.draw(pedestal);
	m_window.draw(PlayerSprite);
	timeRelic.render(m_window);
	m_window.draw(firstEnemy.EnemySprite);
	m_window.draw(heartSprite);
	m_window.draw(timeLeft);
	button1.render(m_window);
	button2.render(m_window);
	button3.render(m_window);

	secondEnemy.render(m_window);

	if ((levelCountdown / 60) > 3)
	{
		endScreen.setFillColor(sf::Color(0, 0, 0, 0));
		greyOut = 0;
	}
	if ((levelCountdown / 60) < 3)
	{
		greyOut+=2;
		if (greyOut > 255)
		{
			greyOut = 255;
		}
		endScreen.setFillColor(sf::Color(0, 0, 0, greyOut));
	}
	if (PlayerPos.x > 1916)
	{
		endScreen.setFillColor(sf::Color(0, 0, 0, 255));
	}
	m_window.draw(endScreen);

	if (levelCountdown / 60 == 0 && winState == false)
	{
		m_window.draw(retry);
	}
	m_window.draw(winMessage);
}

void Player::snapRelicToHand()
{
	if (PlayerSprite.getGlobalBounds().intersects(timeRelic.relicSprite.getGlobalBounds())&&((sf::Keyboard::isKeyPressed(sf::Keyboard::E)) || sf::Joystick::isButtonPressed(0, 2)))
	{
		holdingRelic = true;
		/*timeRelic.relicPos.x = PlayerPos.x += 20;
		timeRelic.relicPos.y = PlayerPos.y;*/
		
	}
	if (PlayerSprite.getGlobalBounds().intersects(pedestal.getGlobalBounds())&&holdingRelic == true)
	{
		holdingRelic = false;
		timeRelic.relicPos = sf::Vector2f(108, 515);
		//levelCountdown += 300;
	}
	if (holdingRelic == true)
	{
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
		//lives++;
	}

	if (PlayerSprite.getGlobalBounds().intersects(secondEnemy.EnemySprite2.getGlobalBounds()) && playerIsAttacking())
	{
		secondEnemy.enemyIsAlive = false;
		//lives++;
	}
	else if (PlayerSprite.getGlobalBounds().intersects(secondEnemy.EnemySprite2.getGlobalBounds()) && secondEnemy.enemyIsAlive == true && !playerIsAttacking())
	{
		if (healthLossTimer <= 0)
		{
			lives--;
			healthLossTimer = 120;
		}
	}
	
	if (PlayerSprite.getGlobalBounds().intersects(button1.buttonSprite.getGlobalBounds()) && ((sf::Keyboard::isKeyPressed(sf::Keyboard::E)) || sf::Joystick::isButtonPressed(0, 2)))
	{
		if (timeRelic.relicPos == sf::Vector2f(108, 515))
		{
			if (button1.buttonPressed == false)
			{
				button1.isAnimating = true;
				if (relicTimer <= 0)
				{
					timeRelic.randomPos();
					relicTimer = 120;
				}
			}
			button1.buttonPressed = true;
		}
	}
	if (PlayerSprite.getGlobalBounds().intersects(button2.buttonSprite.getGlobalBounds()) && ((sf::Keyboard::isKeyPressed(sf::Keyboard::E)) || sf::Joystick::isButtonPressed(0, 2)))
	{
		if (timeRelic.relicPos == sf::Vector2f(108, 515))
		{
			if (button2.buttonPressed == false)
			{
				button2.isAnimating = true;
				if (relicTimer <= 0)
				{
					timeRelic.randomPos();
					relicTimer = 120;
				}
			}
			button2.buttonPressed = true;
		}
	}
	if (PlayerSprite.getGlobalBounds().intersects(button3.buttonSprite.getGlobalBounds()) && ((sf::Keyboard::isKeyPressed(sf::Keyboard::E)) || sf::Joystick::isButtonPressed(0, 2)))
	{
		if (timeRelic.relicPos == sf::Vector2f(108, 515))
		{
			if (button3.buttonPressed == false)
			{
				button3.isAnimating = true;
				if (relicTimer <= 0)
				{
					timeRelic.randomPos();
					relicTimer = 120;
				}
			}
			button3.buttonPressed = true;
		}
	}
		
}
void Player::keepPlayerOnBlock(float t_blockYPos)
{
	if (currentlyJumping == true)
	{
		if (velocityY < 2)
		{
			PlayerPos.y = t_blockYPos + 64;
		}

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -50))
	{
		return true;
	}
	return false;
}

