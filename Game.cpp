#include "Game.h"
#include "Constants.h"

Game::Game()
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris") {}


//let the blocks drop
void Game::run() {
    sf::Clock clock;
    float timer = 0.0f;
    float delay = 0.5f;

    while (window.isOpen()) {
        float time = clock.restart().asSeconds();
        timer += time;

        processInput();

        if (timer > delay) {
            current.move(0, 1); // auto fall
            timer = 0;
        }

        update();
        render();
    }
}


//input
void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) current.move(-1, 0);
            if (event.key.code == sf::Keyboard::Right) current.move(1, 0);
            if (event.key.code == sf::Keyboard::Down) current.move(0, 1);
            if (event.key.code == sf::Keyboard::Up) current.rotate();
        }
    }
}

void Game::update() {
    // TODO: Check collision, lock piece, generate new one, etc.
}

void Game::render() {
    window.clear();
    board.draw(window);
    current.draw(window);
    window.display();
}
