#ifndef FOOD_H
#define FOOD_H
#include <SFML/Graphics.hpp>

class Food: public sf::RectangleShape
{
public:
    Food();
    void update();
    void display(sf::RenderWindow& window);
    void setRandomPos();

    sf::Vector2f getFoodPos();

private:
    float x;
    float y;
    int heightY = 600;
    int weightX = 800;
    std::vector<int> xCells;
    std::vector<int> yCells;


    sf::RenderWindow* window;
};

#endif // FOOD_H
