#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include <SFML/Graphics.hpp>

#include "OBJETO.h"

class CAR : public Objeto
{
    private:
        sf::Texture t_Car;
        sf::Sprite s_Car;
    public:
        CAR();
        //void draw(RenderWindow *r);
        sf::Sprite getSprite();
};

#endif // CAR_H_INCLUDED
