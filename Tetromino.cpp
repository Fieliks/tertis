#include "Tetromino.h"
#include "Constants.h"

Tetromino::Tetromino() {
    // Example shape (line)
    shape = { {4, 0}, {5, 0}, {6, 0}, {7, 0} };
    color = sf::Color::Cyan;

    blockShape.setSize(sf::Vector2f(BLOCK_SIZE - 1, BLOCK_SIZE - 1));
    blockShape.setFillColor(color);
}

void Tetromino::rotate() {
    // TODO: Add rotation logic
}


//Causing the figures to move left and right with elegance
void Tetromino::move(int dx, int dy) {
    for (auto& b : shape)
        b += sf::Vector2i(dx, dy);
}


//Convene them in harmonious unity.
void Tetromino::draw(sf::RenderWindow& window) {
    for (auto& b : shape) {
        blockShape.setPosition(b.x * BLOCK_SIZE, b.y * BLOCK_SIZE);
        window.draw(blockShape);
    }
}

std::vector<sf::Vector2i> Tetromino::getBlocks() const {
    return shape;
}
