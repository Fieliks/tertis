#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Tetromino.h"

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    Board board;
    Tetromino current;

    void processInput();
    void update();
    void render();
};