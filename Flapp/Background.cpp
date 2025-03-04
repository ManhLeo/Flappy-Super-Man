#include "Background.h"

Background::Background(sf::Texture& texture, float initialPosition) {
    backgroundSprite.setTexture(texture);
    position = initialPosition;
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
}

Background::Background() { }

