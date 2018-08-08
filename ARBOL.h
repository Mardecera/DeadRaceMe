#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "OBJETO.h"

class Arbol : public Objeto
{
    private:
        sf::Texture t_Arbol;
        sf::Sprite s_Arbol;

    public:
        Arbol();
        sf::Sprite getSprite();
};

#endif // ARBOL_H_INCLUDED
