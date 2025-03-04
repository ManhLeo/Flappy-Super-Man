
// Bird.h
#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include"Default.h"
#include "Pipe.h"


class Bird {
public:
    Bird();
    Bird(const sf::Texture& texture);
    void update();
    void jump();
    void resetbird();
    sf::Sprite getSprite() const;
    bool hasPassedPipe(const Pipe& pipe) const;


private:
    sf::Sprite sprite;
    sf::Vector2f position;
    float velocity;
};

#endif // BIRD_H

