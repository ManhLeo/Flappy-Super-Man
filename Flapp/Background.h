#pragma once
// Background.h
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background {
public:
    Background();
    Background(sf::Texture& texture, float initialPosition);
    void draw(sf::RenderWindow& window);

private:
    sf::Sprite backgroundSprite;
    float position=0;
};

#endif // BACKGROUND_H

