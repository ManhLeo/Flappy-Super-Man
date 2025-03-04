
//Pipe.h
#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>
#include"Default.h" 


class Pipe {
public:
    Pipe(float Xval, float Yval, sf::Texture* pipeUpTexture, sf::Texture* pipeDownTexture,float* Speed);
    void move(float elapsedTime);
    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;

    // Thêm hàm set position vào Pipe.h
    void setPosition(float x, float y);


    bool isScored() const;
    void setScored(bool scored);
    void resetPosition();
    void resetpipe(float, float);

    sf::FloatRect getGlobalBounds(int = 0) const;



private:
    sf::RectangleShape pipeUp;
    sf::RectangleShape pipeDown;
    sf::Vector2f position;
    float pipeSpeed;
    bool scored;
};

#endif // PIPE_H
