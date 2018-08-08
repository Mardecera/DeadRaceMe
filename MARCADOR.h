#ifndef MARCADOR_H_INCLUDED
#define MARCADOR_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "OBJETO.h"

class Marcador : public Objeto
{
    private:
        int limite;
        sf::Texture t_Marca;
        sf::Sprite s_Marca;

    public:
        Marcador();
        void subir(float);
        int getLimit();
        sf::Sprite getSprite();
};

#endif // MARCADOR_H_INCLUDED
