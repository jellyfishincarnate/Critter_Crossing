#pragma once

#  include "Vector2.h"
#  include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();

	bool initialiseSprite(sf::Texture& texture, std::string filename);
	sf::Sprite* getSprite();
	Vector2* getVector();
	void setVector(float x, float y);
	void setVector(float x, float y, bool normalise);
	float speed = 0;
	void move(float x, float y);
	void setPosition(float x, float y);
	void update(float dt);
	bool checkIntersection(sf::FloatRect otherBox);
	int checkSide(sf::FloatRect otherBox);
	void bounce(int side);
	bool checkOnScreen(sf::RenderWindow* _window);
	Vector2* getPosition();
	void render(sf::RenderWindow* _window);
	Vector2* getOffset();
	void setOffset(float x, float y);

	bool visibility = true;

private:
	sf::Sprite* sprite = nullptr;
	Vector2* vector = nullptr;
	Vector2* position = nullptr;
	Vector2* offset = nullptr;

	void updateSprite();
};