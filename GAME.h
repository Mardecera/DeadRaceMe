#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "CAR.h"
#include "ARBOL.h"
#include "JUGADOR.h"
#include "MARCADOR.h"

using namespace std;

class Game
{
    public:
        Game(sf::RenderWindow& renderWindow);
        void start();
        void draw();
        void cargarArboles();
        void cargarEnemigos();
        void desplazar();
        void clean();
        void colision();
        void loser();
        void win();
        void addEnemy();
        void addArbol();
        string to_string(float);

    private:
        Jugador miCar;
        Marcador marca;
        vector <Arbol*> arboles;
        vector <CAR*> enemigos;
        sf::Clock clock, clockGame;
        sf::Texture tBG;
        sf::Sprite sBG;
        bool gameOver;
        sf::RenderWindow* m_renderWindow;

};

#endif // GAME_H_INCLUDED
