// Score.h
#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include "Default.h"
#include <fstream>

class Score {
private:
    int score;
    int highScore;
    sf::Font font;
    sf::Text scoreText;
    sf::Text highScoreText;

public:
    Score();
    void draw(sf::RenderWindow& window);
    void increase();
    
    int getScore() const;
    void setHighScore(int newHighScore);
    int getHighScore() const;
    void reset();  

    void saveHighScoreToFile(const std::string& filename) const;
    void loadHighScoreFromFile(const std::string& filename);



};

#endif // SCORE_H
