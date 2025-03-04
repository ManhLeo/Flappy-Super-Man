#include "Menu.h"

Menu::Menu() {
    if (!backgroundTexture.loadFromFile(MenuBackground)) {
        std::cout << "Error loading background image" << std::endl;
    }

    if (!font.loadFromFile(FONT)) {
        std::cout << "Error loading font" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);



    startText.setFont(font);
    startText.setCharacterSize(50);
    startText.setFillColor(sf::Color::White);
    startText.setString("* Start Game");
    startText.setPosition(200, 400);

    exitText.setFont(font);
    exitText.setCharacterSize(50);
    exitText.setFillColor(sf::Color::White);
    exitText.setString("* Exit");
    exitText.setPosition(200, 450);


    againText.setFont(font);
    againText.setCharacterSize(50);
    againText.setFillColor(sf::Color::White);
    againText.setString("* Play Again");
    againText.setPosition(200, 400);

    loseText.setFont(font);
    loseText.setCharacterSize(70);
    loseText.setFillColor(sf::Color::Cyan);
    loseText.setString("You Lose");
    loseText.setPosition(200, 250);
}

Menu::~Menu()
{ }


int Menu::runMenu(sf::RenderWindow& window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    // Chọn tùy chọn trước
                    selectedOption = (selectedOption - 1 + 2) % 2;
                    updateOptionColors();
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    // Chọn tùy chọn tiếp theo
                    selectedOption = (selectedOption + 1) % 2;
                    updateOptionColors();
                }
                else if (event.key.code == sf::Keyboard::Return) {
                    // Xử lý chọn tùy chọn
                    handleOptionSelection(window);
                    return selectedOption;
                }
            }
        }

        
        window.clear();
        window.draw(backgroundSprite);
        window.draw(startText);
        window.draw(exitText);
        window.display();
    }

    return -1; // Không thực hiện lựa chọn nào
}

int Menu::runMenuAgain(sf::RenderWindow& window, int SCORE, int HIGHSCORE) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    // Chọn tùy chọn trước
                    selectedOption = (selectedOption - 1 + 3) % 3;
                    updateOptionColors();
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    // Chọn tùy chọn tiếp theo
                    selectedOption = (selectedOption + 1) % 3;
                    updateOptionColors();
                }
                else if (event.key.code == sf::Keyboard::Return) {
                    // Xử lý chọn tùy chọn
                    handleOptionSelection(window);
                    return selectedOption;
                }
            }
        }

        sf::Text SCOREText, HIGHSCOREText;
        font.loadFromFile(FONT);

        SCOREText.setFont(font);
        SCOREText.setCharacterSize(40);
        SCOREText.setFillColor(sf::Color::Cyan);
        SCOREText.setString("Score: " + std::to_string(SCORE));
        SCOREText.setPosition(900, 10);

        HIGHSCOREText.setFont(font);
        HIGHSCOREText.setCharacterSize(40);
        HIGHSCOREText.setFillColor(sf::Color::Cyan);
        HIGHSCOREText.setString("Highscore: " + std::to_string(HIGHSCORE));
        HIGHSCOREText.setPosition(900, 50);

        
        window.clear();
        window.draw(backgroundSprite);
        window.draw(againText);
        window.draw(exitText);
        window.draw(loseText);
        

        window.draw(SCOREText);
        window.draw(HIGHSCOREText);

        window.display();
    }

    return -1; // Không thực hiện lựa chọn nào
}


void Menu::updateOptionColors() {
    // Đặt màu sắc cho các tùy chọn dựa trên tùy chọn được chọn
    startText.setFillColor(selectedOption == 0 ? sf::Color::Blue : sf::Color::White);
    exitText.setFillColor(selectedOption == 1 ? sf::Color::Blue : sf::Color::White);
    againText.setFillColor(selectedOption == 0 ? sf::Color::Blue : sf::Color::White);
}

void Menu::handleOptionSelection(sf::RenderWindow& window) {
    // Xử lý khi người chơi chọn tùy chọn
    if (selectedOption == 0) {
        //Start
        window.clear();
        window.display();
    }
    else if (selectedOption == 1) {
        // Exit
        window.close();
    }
}

void Menu::updateScores(int newScore, int newHighscore) {
    SCORE = newScore;
    HIGHSCORE = newHighscore;
}