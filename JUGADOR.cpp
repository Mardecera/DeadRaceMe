#include <iostream>
#include <SFML/Graphics.hpp>
#include "JUGADOR.h"

Jugador::Jugador()
{
    //282 - (21.42 / 2) = 271.29
    posX = 271;
    posY = 360;
    tCar.loadFromFile("Sprite/Car_yo.png");
    sf::Sprite sprite(tCar, sf::IntRect(0, 0, 100, 200));
    sprite.setScale(sf::Vector2f(0.18f, 0.18f)); //18x36
    sCar = sprite;

}


void Jugador::moveLeft()
{
    posX -= 4;
    if(posX <= 204)
        posX = 204;
}

void Jugador::moveRight()
{
    posX += 4;
    if(posX >= 337.58) //360-21.42
        posX = 337.58;
}

int Jugador::getPosX()
{
    return posX;
}

int Jugador::getPosY()
{
    return posY;
}

sf::Sprite Jugador::getSprite()
{
    return sCar;
}

sf::Sprite Jugador::getSpriteBoom()
{
    return sBoom;
}

void Jugador::velocidad(sf::Clock clock)
{
    d += 1;
    t += clock.getElapsedTime().asSeconds();
    v = (36 * d) / (10 * t);

}

float Jugador::getTiempo()
{
    int time = t;
    return time;
}

void Jugador::invisible()
{
    sCar.setColor(sf::Color(255, 255, 255, 0));
}

void Jugador::cargarBoom()
{
    tBoom.loadFromFile("Sprite/boom.png");
    sf::IntRect _rBoom(0, 0, tBoom.getSize().x / float(3), tBoom.getSize().y);
    rBoom = _rBoom;
    sf::Sprite _sBoom(tBoom, rBoom);
    _sBoom.setPosition(posX -10 , posY -10);
    sBoom = _sBoom;
}


void Jugador::boom()
{
    rBoom.left += rBoom.width;
    sBoom.setTextureRect(rBoom);
}

float Jugador::getVelocidad()
{
    int vel = v;
    return vel;
}
