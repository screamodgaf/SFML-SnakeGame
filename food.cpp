#include "food.h"
#include <ctime>
#include <iostream>
Food::Food()
{
    srand(time(nullptr));
    weightX = 800; // x
    heightY = 600; // y

    setSize(sf::Vector2f(20,20));

    for (int i = 0; i < weightX; i+=20)
        xCells.push_back(i);


    for (int i = 0; i < heightY; i+=20)
        yCells.push_back(i);


    setRandomPos();
}

void Food::update()
{

}

void Food::display(sf::RenderWindow &_window)
{
    window = &_window;
    window->draw(*this);
    //std::cout << "food: " << getPosition().x << " " << getPosition().y << std::endl;
}

void Food::setRandomPos()
{
   x =  xCells[std::rand()% xCells.size()];
   y =  yCells[std::rand()% yCells.size()];
   this->setPosition(sf::Vector2f(x,y));
   setSize(sf::Vector2f(20,20));
}

sf::Vector2f Food::getFoodPos()
{
    return  this->getPosition() ;
}


