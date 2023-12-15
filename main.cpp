#include <iostream>
#include "mover.h"
#include "food.h"
#include <ctime>
#include <vector>



void drawMover(Mover& m, sf::RenderWindow &window)
{
    m.update();
    m.edges();
    m.checkFoodAndSnakePos();
    m.checkIfNotMovingBack();
    m.display(window);
}


void drawFood(Food& food, sf::RenderWindow &window)
{
    //f.update();
    food.display(window);
}

int main()
{
    srand(time(nullptr));
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "SFML");
    window.setFramerateLimit(10);
    Food food;
    Mover *m = new Mover (food);


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            case sf::Event::EventType::KeyPressed:
                if(sf::Keyboard::Key::Up == event.key.code)
                    m->setDirection(0,-1);

                if(sf::Keyboard::Key::Down == event.key.code)
                    m->setDirection(0,1);

                if(sf::Keyboard::Key::Left == event.key.code)
                    m->setDirection(-1,0);

                if(sf::Keyboard::Key::Right == event.key.code)
                    m->setDirection(1,0);

                if(sf::Keyboard::Key::Q == event.key.code)
                    m->test_displayPositions();

            }
        } // end of events


        drawMover(*m, window);
        drawFood(food, window);

        window.display();
        window.clear();
    }
}
