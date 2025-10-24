
#include "Game.h"
#include <iostream>
#include "GameObject.h"

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


	animals[0].loadFromFile("../Data/Images/kenney_animalpackredux/PNG/Square/bear.png");
	animals[1].loadFromFile("../Data/Images/kenney_animalpackredux/PNG/Square/buffalo.png");
	animals[2].loadFromFile("../Data/Images/kenney_animalpackredux/PNG/Square/chick.png");

	passports[0].loadFromFile("../Data/Images/kenney_animalpackredux/PNG/Square/bear.png");
	passports[1].loadFromFile("../Data/Images/kenney_animalpackredux/PNG/Square/buffalo.png");
	passports[2].loadFromFile("../Data/Images/kenney_animalpackredux/PNG/Square/chick.png");

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

	newAnimal();

	


  return true;
}

void Game::newAnimal()
{
	passport_accepted = false;
	passport_rejected = false;

	int animal_index = rand() % 3;
	int passport_index = rand() % 3;

	if (animal_index == passport_index)
	{
		should_accept = true;
	}
	else
	{
		should_accept = false;
	}

	character->setTexture(animals[animal_index], true);
	character->setScale(1.8, 1.8);
	character->setPosition(window.getSize().x / 12, window.getSize().y / 12);

	passport->setTexture(passports[passport_index], true);
	passport->setScale(0.6, 0.6);
	passport->setPosition(window.getSize().x / 2, window.getSize().y / 3);
	
}

void Game::dragSprite(sf::Sprite* sprite)
{
	if (sprite != nullptr)
	{
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);

		sf::Vector2f drag_position = mouse_positionf;
		sprite->setPosition(drag_position.x, drag_position.y);
	}
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
		window.draw(*character);
		window.draw(*passport);
	}
}

//mouse handling



void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::mouseButtonPressed(sf::Event event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2i click = sf::Mouse::getPosition(window);
		sf::Vector2f clickf = static_cast<sf::Vector2f>(click);

		if (passport->getGlobalBounds().contains(clickf))
		{
			dragged = passport;
		}
	}
}

void Game::mouseButtonReleased(sf::Event event)
{
	
}

void Game::keyPressed(sf::Event event)
{

}


