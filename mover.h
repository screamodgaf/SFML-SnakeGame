#ifndef MOVER_H
#define MOVER_H
#include <SFML/Graphics.hpp>
class Food;
class Mover: public sf::RectangleShape
{
public:
    Mover(Food &f);
    void update();
    void display(sf::RenderWindow& window);
    void edges();
    void setDirection(int x, int y);
    void checkFoodAndSnakePos();
    void checkIfNotMovingBack();
    void test_displayPositions();
    std::vector<Mover> getObjects();

private:
    float x;
    float y;
    float xSpeed;
    float ySpeed;
    float scale;
    int foodSize;
    Food *food;
    sf::Vector2f posXY;

    std::vector<sf::Vector2f> v_positions;
    //std::vector<Mover> v_objects;
    sf::RenderWindow* window;
};

#endif // MOVER_H
