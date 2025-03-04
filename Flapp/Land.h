
#pragma once
// Land.h
#ifndef LAND_H
#define LAND_H

#include <SFML/Graphics.hpp>
#include"Default.h"

class Land {
public:
    Land();
    Land(sf::Texture& texture, float initialPosition);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds() const;
private:
    sf::Sprite LandSprite;
    float position;
};

#endif // LAND_H
