#include "Score.h"

Score::Score() {
    font.loadFromFile(FONT);

    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(500, 20);
    scoreText.setString("Score: " + std::to_string(score));

    //highScoreText.setFont(font);
    //highScoreText.setCharacterSize(30);
    //highScoreText.setFillColor(sf::Color::White);
    //highScoreText.setPosition(20, 60);
    //highScoreText.setString("High Score: " + std::to_string(highScore));
}

void Score::draw(sf::RenderWindow& window) {
    window.draw(scoreText);
    //window.draw(highScoreText);
}

void Score::increase() {
    ++score;
    if (score > highScore) {
        highScore = score;
        highScoreText.setString("High Score: " + std::to_string(highScore));
    }
    scoreText.setString("Score: " + std::to_string(score));
}

int Score::getScore() const {
    return score;
}

void Score::setHighScore(int newHighScore) {
    highScore = newHighScore;
    highScoreText.setString("High Score: " + std::to_string(highScore));
}

int Score::getHighScore() const {
    return highScore;
}

void Score::reset() {
    score = 0;
    scoreText.setString("Score: " + std::to_string(score));
}


void Score::saveHighScoreToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if (file.is_open()) {
        file << highScore;
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}


void Score::loadHighScoreFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
}
