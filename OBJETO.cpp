#include "OBJETO.h"

void Objeto::setPosition(float _x, float _y)
{
    posX = _x;
    posY = _y;
}

void Objeto::desplazar(float _y)
{
    posY += _y;
}

float Objeto::getPosX()
{
    return posX;
}

float Objeto::getPosY()
{
    return posY;
}

void Objeto::setPosX(float x)
{
    posX = x;
}

void Objeto::setPosY(float y)
{
    posY = y;
}
