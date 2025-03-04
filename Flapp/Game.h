#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipe.h"
#include "Land.h"
#include "Background.h"
#include "Default.h"
#include "Score.h"
#include "Menu.h"

class Game {
public:
    Game();
    void run();
    void resetGame();
    void Playagain();

private:
    void handleEvents();
    void update(float elapsedTime);
    void render();
    bool gameStarted;


private:
    sf::RenderWindow window;
    sf::Texture birdTexture;
    Bird bird;
    sf::Texture backgroundTexture;
    Background background;
    sf::Texture landTexture;
    Land land;
    sf::Texture pipeUpTexture;
    sf::Texture pipeDownTexture;
    std::vector<Pipe> pipes;
    Score scoreManager;
};

#endif // GAME_H
