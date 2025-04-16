#pragma once
#include <SFML/Graphics.hpp>
#include "Tetromino.h"
#include "Constants.h"

class Board {
public:
    Board();

    void draw(sf::RenderWindow& window);
    bool isCollision(const Tetromino& tetromino);
    void lockTetromino(const Tetromino& tetromino);
    void clearLines();

private:
    int grid[ROWS][COLS];
    sf::RectangleShape blockShape;

    void drawBlock(int x, int y, sf::Color color, sf::RenderWindow& window);
};
