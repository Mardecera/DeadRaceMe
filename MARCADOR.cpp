#include <iostream>
#include <SFML/Graphics.hpp>
#include "MARCADOR.h"

Marcador::Marcador()
{
    setPosX(float(23));
    setPosY(float(350));
    limite = 40;
    t_Marca.loadFromFile("Sprite/marcador.png");
    sf::Sprite sprite(t_Marca, sf::IntRect(0, 0, 100, 188));
    sprite.setScale(sf::Vector2f(0.18f, 0.18f)); //18x33.3
    s_Marca = sprite;
}

void Marcador::subir(float _y)
{
    setPosY(getPosY() - _y);
}

sf::Sprite Marcador::getSprite()
{
    return s_Marca;
}

int Marcador::getLimit()
{
    return limite;
}
