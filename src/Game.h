
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

private:
    enum gameState
    {
        MENU,
        GAMEPLAY
    };

 private:
     sf::RenderWindow& window;
     sf::Sprite* character;
     sf::Sprite* passport;
     sf::Texture* animals;
     sf::Texture* passports;

     sf::Text menuText;
     sf::Font font;
     sf::Sprite background;
     sf::Texture backgroundTexture;

     enum gameState state;

};

#endif // PLATFORMER_GAME_H
