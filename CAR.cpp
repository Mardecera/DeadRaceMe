#include <iostream>
#include <SFML/Graphics.hpp>
#include "CAR.h"
#include <stdlib.h>

CAR::CAR()
{
    int ran = rand()%3;
    sf::IntRect t;
    if(ran == 0)
    {
        t_Car.loadFromFile("Sprite/carEnemyYellow.png");
        t.width = 100;
        t.height = 200;
    }
    else if(ran == 1)
    {
        t_Car.loadFromFile("Sprite/carEnemyBlue.png");
        t.width = 100;
        t.height = 200;
    }
    else
    {
        t_Car.loadFromFile("Sprite/carEnemyRed.png");
        t.width = 100;
        t.height = 229;
    }
    sf::Sprite sprite(t_Car, t);
    sprite.setScale(sf::Vector2f(0.18f, 0.18f)); //18x36
    s_Car = sprite;
}

sf::Sprite CAR::getSprite()
{
    return s_Car;
}

/*void CAR::draw(RenderWindow* renderWindow)
{
    s_Car.move(posX, posY);
    renderWindow->draw(s_Car);
}*/

