
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void newAnimal();
  void dragSprite(sf::Sprite* sprite);
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void mouseButtonPressed(sf::Event event);
  void mouseButtonReleased(sf::Event event);
  void keyPressed(sf::Event event);

private:
    enum gameState
    {
        MENU,
        GAMEPLAY
    };

 private:
     sf::RenderWindow& window;
     sf::Sprite* character = nullptr;
     sf::Sprite* passport = nullptr;
     sf::Texture* animalsTexture = nullptr;
     sf::Text menuText;
     sf::Font font;
     sf::Sprite background;
     sf::Texture backgroundTexture;

     sf::Texture* animals = new sf::Texture[3];
     sf::Texture* passports = new sf::Texture[3];

     sf::Sprite* dragged = nullptr;

     bool passport_accepted; 
     bool passport_rejected;
     bool should_accept;

     enum gameState state;

};

#endif // PLATFORMER_GAME_H
