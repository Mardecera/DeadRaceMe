#include <iostream>
#include <SFML/Graphics.hpp>
#include "ARBOL.h"

Arbol::Arbol()
{
    //282 - (21.42 / 2) = 271.29
    setPosX(271);
    setPosY(360);
    t_Arbol.loadFromFile("Sprite/arbol.png");
    sf::Sprite sprite(t_Arbol, sf::IntRect(0, 0, 150, 87));
    sprite.setScale(sf::Vector2f(0.5f, 0.5f));
    s_Arbol = sprite;
}

sf::Sprite Arbol::getSprite()
{
    return s_Arbol;
}
