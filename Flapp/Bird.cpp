#include "Bird.h"

Bird::Bird() { }

Bird::Bird(const sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2);
    velocity = 0.0f;
    position = sprite.getPosition();
}

void Bird::update() {
    velocity += GRAVITY;
    sprite.move(0, velocity);
}

void Bird::jump() {
    velocity = JUMP_HEIGHT;
}
void Bird::resetbird()
{
    // Đặt lại vị trí và tốc độ của Bird về giá trị mặc định
    sprite.setPosition(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2);
    velocity = 0.0f;
}

sf::Sprite Bird::getSprite() const {
    return sprite;
}
bool Bird::hasPassedPipe(const Pipe& pipe) const {
    return (position.x > pipe.getPosition().x + PIPE_WIDTH);
}

