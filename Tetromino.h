#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Tetromino {
public:
    Tetromino();

    void rotate();
    void move(int dx, int dy);
    void draw(sf::RenderWindow& window);
    std::vector<sf::Vector2i> getBlocks() const;

private:
    std::vector<sf::Vector2i> shape; // positions in grid
    sf::Color color;
    sf::RectangleShape blockShape;

    void updateBlockShape();
};
