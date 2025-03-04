
#include "Land.h"

Land::Land() { }

Land::Land(sf::Texture& texture, float initialPosition) {
    LandSprite.setTexture(texture);
    position = initialPosition;

    // Set the position at the bottom of the window
    LandSprite.setPosition(position, SCREEN_HEIGHT - LAND_HEIGHT);
}

void Land::draw(sf::RenderWindow& window) {
    window.draw(LandSprite);
}

sf::FloatRect Land::getGlobalBounds() const {
    return LandSprite.getGlobalBounds();//trả về hình chữ nhật của đối tượng
}
