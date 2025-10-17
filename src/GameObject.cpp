#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
    sprite = new sf::Sprite;
    vector = new Vector2(0, 0);
    position = new Vector2(0, 0);
    offset = new Vector2(0, 0);
};

GameObject::~GameObject() {

};

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
    if (!texture.loadFromFile(filename))
    {
        std::cout << "no sprite\n";
        return false;
    }
    sprite->setTexture(texture);

    return true;
}

sf::Sprite* GameObject::getSprite()
{
    return sprite;
}

Vector2* GameObject::getVector()
{
    return vector;
}

void GameObject::setVector(float x, float y)
{
    vector->x = x;
    vector->y = y;
}

void GameObject::setVector(float x, float y, bool normalise)
{
    vector->x = x;
    vector->y = y;

    if (normalise)
    {
        vector->normalise();
    }
}

void GameObject::move(float x, float y)
{
    position->x += x;
    position->y += y;
}

void GameObject::setPosition(float x, float y)
{
    position->x = x;
    position->y = y;
}

void GameObject::update(float dt)
{
    move(vector->x * speed * dt, vector->y * speed * dt);
}

bool GameObject::checkIntersection(sf::FloatRect otherBox)
{
    updateSprite();
    sf::FloatRect thisBox = sprite->getGlobalBounds();
    return (
        thisBox.left < otherBox.left + otherBox.width &&
        thisBox.left + thisBox.width > otherBox.left &&
        thisBox.top < otherBox.top + otherBox.height &&
        thisBox.top + thisBox.height > otherBox.top);
}

int GameObject::checkSide(sf::FloatRect otherBox)
{
    if (checkIntersection(otherBox))
    {
        updateSprite();
        sf::FloatRect thisBox = sprite->getGlobalBounds();
        float topOverlap = (thisBox.top + otherBox.height) - otherBox.top;
        float bottomOverlap = (otherBox.top + otherBox.height) - thisBox.top;
        float leftOverlap = (thisBox.left + thisBox.width) - otherBox.left;
        float rightOverlap = (otherBox.left + otherBox.width) - thisBox.left;

        float smallestOverlap =
            std::min({ topOverlap, bottomOverlap, leftOverlap, rightOverlap });
        if (smallestOverlap == topOverlap)
        {
            return 1;
        }
        else if (smallestOverlap == rightOverlap)
        {
            return 2;
        }
        else if (smallestOverlap == bottomOverlap)
        {
            return 3;
        }
        else if (smallestOverlap == leftOverlap)
        {
            return 4;
        }
    }
    return 0;
}

void GameObject::bounce(int side)
{
    if (side == 0 || side > 4)
    {
        return;
    }
    else if (side == 1 && vector->y > 0)
    {
        vector->y = -vector->y;
    }
    else if (side == 3 && vector->y < 0)
    {
        vector->y = -vector->y;
    }
    else if (side == 2 && vector->x < 0)
    {
        vector->x = -vector->x;
    }
    else if (side == 4 && vector->x > 0)
    {
        vector->x = -vector->x;
    }
}

bool GameObject::checkOnScreen(sf::RenderWindow* _window)
{
    updateSprite();
    sf::FloatRect bounds = sprite->getGlobalBounds();
    sf::Vector2u screen = _window->getSize();

    return !(
        bounds.left + bounds.width < 0 || bounds.left > screen.x ||
        bounds.top + bounds.height < 0 || bounds.top > screen.y);
}

Vector2* GameObject::getPosition()
{
    return position;
}

void GameObject::render(sf::RenderWindow* _window)
{
    updateSprite();
    _window->draw(*sprite);
}

Vector2* GameObject::getOffset()
{
    return offset;
}

void GameObject::setOffset(float x, float y)
{
    offset->x = x;
    offset->y = y;
}

void GameObject::updateSprite()
{
    sprite->setPosition(position->x + offset->x, position->y + offset->y);
}