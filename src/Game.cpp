
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{

	state = MENU;
	character = new sf::Sprite;
	passport = new sf::Sprite;
	sf::Texture* animals = new sf::Texture[3];
	sf::Texture* passports = new sf::Texture[3];

	// Menu

	if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "no font.\n";
	}
	menuText.setString("Critter Crossing");
	menuText.setFont(font);
	menuText.setCharacterSize(45);
	menuText.setColor(sf::Color(255, 255, 255));

	menuText.setPosition(

		window.getSize().x / 2 - menuText.getGlobalBounds().width / 2,
		window.getSize().y / 6 - menuText.getGlobalBounds().height / 2);

	// Gameplay screen
	if (!backgroundTexture.loadFromFile("../Data/WhackaMoleWorksheet/background.png"))
	{
		std::cout << "no bg\n";
	}
	background.setTexture(backgroundTexture);
	background.setScale(1, 1);


  return true;
}

void Game::update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		state = GAMEPLAY;
	};

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		state = MENU;
	};
}

void Game::render()
{
	if (state == MENU)
	{
		window.draw(menuText);
	}
	else if (state == GAMEPLAY)
	{
		window.draw(background);
	}
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{

}


