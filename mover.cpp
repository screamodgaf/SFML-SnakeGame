#include "mover.h"
#include <iostream>
#include <algorithm>
#include "food.h"
Mover::Mover(Food& food_)
{
    x = 0;
    y = 0;
    sf::Vector2f posXY = sf::Vector2f(x,y);
    xSpeed = 1;
    ySpeed = 0;
    scale = 20;
    foodSize = 2;
    food = &food_;

    v_positions.push_back(posXY);
}



void Mover::update()
{
    x = x + xSpeed * scale; // move by scale
    y = y + ySpeed * scale;
    edges();
    posXY = sf::Vector2f(x, y);
    setPosition(posXY);

    v_positions.push_back(posXY); // vector { beginning - 1,2,3,4,5,6 ... - end} // so it displays 1,2,3
        // so if 1 meets 2 and 3, we should reduce to 1

    if(v_positions.size() > foodSize )
        v_positions.erase(v_positions.begin());



}

//==============================================================

void Mover::display(sf::RenderWindow &_window)
{
    setSize(sf::Vector2f(20,20));
    window = &_window;
    this->setFillColor(sf::Color::Yellow);
    window->draw(*this);

    for (int i = 1; i < v_positions.size(); ++i) // cant start from 0 cause then it become part of the tail immidiatly
    {
        sf::RectangleShape r;
        r.setSize(sf::Vector2f(20,20));
        r.setPosition(v_positions[i]);
        r.setFillColor(sf::Color::Red);
        window->draw(r);
    }

   // std::cout << "snake position: " << getPosition().x << " " << getPosition().y << std::endl;
}



void Mover::edges()
{
    if(getPosition().x < 0 )       x = 0;
    if(getPosition().x > 800-20)   x = 800 - 20;
    if(getPosition().y < 0)        y = 0;
    if(getPosition().y > 600-20)   y = 600 - 20;

}

void Mover::setDirection(int x, int y)
{
   xSpeed = x;
   ySpeed = y;
}

void Mover::checkFoodAndSnakePos()
{
    if(this->getPosition() == food->getFoodPos())
    {
       foodSize++;  // make the tail longer
       food->setRandomPos();
    }
}

void Mover::checkIfNotMovingBack()
{
        for (int i = 0; i < v_positions.size(); ++i)
        {
            for (int j = i+1; j < v_positions.size(); ++j)
            {
                if(v_positions[i] == v_positions[j])
                {
                    foodSize=2;
                    v_positions.resize(2);
                    std::cout << "souble" << std::endl;
                }
            }
        }





}

void Mover::test_displayPositions()
{
    std::cout << "current position: " << getPosition().x << " " << getPosition().y << std::endl;

    for (unsigned long long i = 0; i < v_positions.size(); ++i)
    {
       std::cout << i << " current position: " << v_positions[i].x << " " << v_positions[i].y << std::endl;
    }


    exit(0);
}





