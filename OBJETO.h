#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED
#include <SFML/Graphics.hpp>

class Objeto
{
    private:
        float posX;
        float posY;

    public:
        void desplazar(float);
        void setPosition(float, float);
        float getPosX();
        float getPosY();
        void setPosX(float);
        void setPosY(float);
};

#endif // OBJETO_H_INCLUDED
