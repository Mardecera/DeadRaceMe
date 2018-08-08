#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <SFML/Graphics.hpp>

class Jugador
{
    private:
        int puntaje;
        int posX;
        int posY;
        float t;
        float d;
        float gasolina;
        float v;
        sf::Texture tCar;
        sf::Sprite sCar;

    public:
        Jugador();
        void boom();
        void cargarBoom();
        void moveLeft();
        void moveRight();
        int getPosX();
        int getPosY();
        float getTiempo();
        float getVelocidad();
        void velocidad(sf::Clock);
        void invisible();

        sf::Sprite getSprite();
        sf::Sprite getSpriteBoom();
        sf::IntRect rBoom;
        sf::Texture tBoom;
        sf::Sprite sBoom;
};

#endif // JUGADOR_H_INCLUDED
