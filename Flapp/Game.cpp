#include "Game.h"

float Speed = 150.0f;
Game::Game() : window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PBL2 Flappy Super Man"), gameStarted(false){
    window.setFramerateLimit(60);

    birdTexture.loadFromFile(BIRD);
    bird = Bird(birdTexture);

    backgroundTexture.loadFromFile(BACKGROUND);
    background = Background(backgroundTexture, 0);

    landTexture.loadFromFile(LAND);
    land = Land(landTexture, 0);

    pipeUpTexture.loadFromFile(PIPE);
    pipeDownTexture.loadFromFile(PIPE);

    srand((int)time(0));

    for (int i = 0; i < numPipes; ++i) {  
        pipes.push_back(Pipe((float)(SCREEN_WIDTH + i * 350), (float) ( - 412 + rand() % 413), &pipeUpTexture, &pipeDownTexture, &Speed));
    }


    Score scoreManager;
    scoreManager = Score();

}
void Game::run() {
    sf::Clock clock;

    scoreManager.loadHighScoreFromFile(FileHighscore);

    Menu menu;
    bool choice = menu.runMenu(window);
    
    if (choice == 0) {
        // Bắt đầu game
        std::cout << "Starting the game..." << std::endl;
        
        while (window.isOpen()) {
            handleEvents();
            update(clock.restart().asSeconds());
            render();
        }
    }
    else
    {
        scoreManager.saveHighScoreToFile(FileHighscore);
        window.close();
    }
}

void Game::resetGame() {
    for (int i = 0; i < numPipes; ++i) {
        pipes[i].resetpipe((float)(SCREEN_WIDTH + i * 350), (float)(-412 + rand() % 413));
    }
    bird.resetbird();
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PBL2 Flappy Super Man");
    window.setFramerateLimit(60);
}    


void Game::Playagain() {
    sf::Clock clock;
  
    Menu menu;

    int choice = 0;
    resetGame();

    
    while (window.isOpen()) {
        choice = menu.runMenuAgain(window, scoreManager.getScore(), scoreManager.getHighScore());
        menu.updateScores(scoreManager.getScore(), scoreManager.getHighScore());
        
        scoreManager.reset();

        if (choice == 0) {
            std::cout << "Starting the game again..." << std::endl;
            
            while (window.isOpen()) {
                handleEvents();
                update(clock.restart().asSeconds());
                render();
            }
        }
        else {
            scoreManager.saveHighScoreToFile(FileHighscore);
            window.close();
        }
    }
}


void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                gameStarted = true;
                bird.jump();
            }
        }
    }
}

void Game::update(float elapsedTime) {
    if (gameStarted) {
        for (int i = 0; i < numPipes; ++i) {
            pipes[i].move(elapsedTime);
            if (bird.getSprite().getPosition().y < 0) {
                std::cout << "Game Over! Superman hit the sky " << std::endl;
                gameStarted = false;
                Playagain();
            }

            if (pipes[i].getGlobalBounds().intersects(bird.getSprite().getGlobalBounds()) ||
                pipes[i].getGlobalBounds(1).intersects(bird.getSprite().getGlobalBounds())) 
            { 
                std::cout << "Game Over! Superman hit the pipe " << std::endl;
                gameStarted = false;
                Playagain();
               
            }

            if (land.getGlobalBounds().intersects(bird.getSprite().getGlobalBounds())) {
                std::cout << "Game Over! Superman hit the land " << std::endl;
                gameStarted = false;
                Playagain();
            }

            if (pipes[i].getPosition().x + PIPE_WIDTH < bird.getSprite().getPosition().x && !pipes[i].isScored()) {
                pipes[i].setScored(true);
                scoreManager.increase();
                std::cout << "Score: " << scoreManager.getScore() << ",     " << "HighScore: " << scoreManager.getHighScore() << std::endl;
            }
        }

        bird.update();
    }
}

void Game::render() {
    window.clear();
    background.draw(window);   
    window.draw(bird.getSprite());
   
    for (int i = 0; i < numPipes; ++i) {
        pipes[i].draw(window);
    }
    land.draw(window);

    scoreManager.draw(window);


    window.display();
}