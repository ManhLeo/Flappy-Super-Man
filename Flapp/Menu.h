#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "Default.h"


class Menu {
public:
    Menu();

    ~Menu();

    int runMenu(sf::RenderWindow& window);
    int runMenuAgain(sf::RenderWindow& window, int, int);

    void updateScores(int, int);

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Font font;
    sf::Text startText;
    sf::Text exitText;
    sf::Text againText;
    sf::Text loseText;

    int SCORE;
    int HIGHSCORE;

    // Tùy chọn được chọn (0: Restart, 1: Exit)
    int selectedOption;

    // Cập nhật màu sắc của các tùy chọn
    void updateOptionColors();

    // Xử lý sự kiện khi chọn tùy chọn
    void handleOptionSelection(sf::RenderWindow& window);
};

#endif // MENU_H
