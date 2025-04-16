#include "Board.h"
#include "Constants.h"

Board::Board() {
    for (int y = 0; y < ROWS; ++y)
        for (int x = 0; x < COLS; ++x)
            grid[y][x] = 0;

    blockShape.setSize(sf::Vector2f(BLOCK_SIZE - 1, BLOCK_SIZE - 1));
}


//Draw blocks in the render window
void Board::draw(sf::RenderWindow& window) {
    for (int y = 0; y < ROWS; ++y)
        for (int x = 0; x < COLS; ++x)
            if (grid[y][x])
                drawBlock(x, y, sf::Color::White, window);
}


//draw block
void Board::drawBlock(int x, int y, sf::Color color, sf::RenderWindow& window) {
    blockShape.setFillColor(color);
    blockShape.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
    window.draw(blockShape);
}

bool Board::isCollision(const Tetromino& tetromino) {
    // TODO: Add collision logic
    return false;
}


//Generate blocks
void Board::lockTetromino(const Tetromino& tetromino) {
    for (auto b : tetromino.getBlocks())
        if (b.y >= 0 && b.y < ROWS && b.x >= 0 && b.x < COLS)
            grid[b.y][b.x] = 1;
}

void Board::clearLines() {
    // TODO: Add line clearing logic
}
