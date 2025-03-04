#include "Pipe.h"
Pipe::Pipe(float Xval, float Yval, sf::Texture* pipeUpTexture, sf::Texture* pipeDownTexture, float* Speed) {
    position = sf::Vector2f(Xval, Yval);
    *Speed += 3;
    pipeSpeed = (*Speed);

    
    // PipeUp
    pipeUp.setSize(sf::Vector2f(PIPE_WIDTH, PIPE_HEIGHT));
    pipeUp.setPosition(position);

    // PipeDown
    pipeDown.setSize(sf::Vector2f(PIPE_WIDTH, PIPE_HEIGHT));
    pipeDown.setPosition(position.x, position.y + PIPE_GAP);


    // Set textures
    pipeUp.setTexture(pipeUpTexture);
    pipeDown.setTexture(pipeDownTexture);
}

void Pipe::move(float elapsedTime) {
    position.x -= pipeSpeed * elapsedTime;
    pipeUp.setPosition(position);
    pipeDown.setPosition(position.x, position.y + PIPE_GAP + PIPE_HEIGHT );

}

void Pipe::draw(sf::RenderWindow& window) {
    window.draw(pipeUp);
    window.draw(pipeDown);
}

// Thêm định nghĩa cho hàm set position vào Pipe.cpp
void Pipe::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
    pipeUp.setPosition(position);
    pipeDown.setPosition(position.x, position.y + PIPE_GAP);
}


sf::Vector2f Pipe::getPosition() const {
    return position;
}

bool Pipe::isScored() const {
    return scored;
}

void Pipe::setScored(bool scored) {
    this->scored = scored;
}

void Pipe::resetPosition() {
    position.x = SCREEN_WIDTH;
    position.y = -412 + rand() % 413;
    scored = false;
    // Đặt lại vị trí cho cả pipeUp và pipeDown
    setPosition(position.x, position.y);
}


sf::FloatRect Pipe::getGlobalBounds(int i) const {
    if(i==1) return pipeDown.getGlobalBounds();
    return pipeUp.getGlobalBounds();
}
void Pipe::resetpipe(float startX, float startY) {
    // Đặt lại vị trí của ống về giá trị mặc định
    position = sf::Vector2f(startX, startY);
    scored = false; // Đặt lại trạng thái scored về false khi ống được reset
}