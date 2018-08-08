#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>

#include "GAME.h"
#include "CAR.h"
#include "JUGADOR.h"

using namespace std;

Game::Game(sf::RenderWindow &renderWindow): m_renderWindow(&renderWindow)
{
    cargarArboles();
    cargarEnemigos();
    gameOver = false;
    tBG.loadFromFile("Sprite/Sprite-background.png");
    sf::Sprite sprite(tBG);
    sBG = sprite;
}

void Game::cargarArboles()
{
    int X = 75, Y = 416;
    for(int i = 1; i < 13; i++)
    {
        Arbol *a = new Arbol;
        if(X == 75)
            X += 40;
        else
            X -= 40;
        Y -= 40;
        a->setPosition(X, Y);
        arboles.push_back(a);
    }
}

void Game::cargarEnemigos()
{
    int X = 205, Y;
    ///A = 205 to 385 ; H = 420
    ///385 - 205 = 180 - 18 = 162 px para dibujar en X
    CAR *c = new CAR;
    X += rand() % 150;
    Y = -37;
    c->setPosition(X, Y);
    enemigos.push_back(c);
}

void Game::addArbol()
{
    int X, Y;
    Arbol *arbolFinal = arboles.back();
    Arbol *a = new Arbol;
    Y = arbolFinal->getPosY() - 40;
    if(arbolFinal->getPosX() == 75)
        X = 115;
    else
        X = 75;
    a->setPosition(X, Y);
    arboles.push_back(a);
}

void Game::addEnemy()
{
    int X , Y = -10, r = rand()%4 + 1;
    for(int i = 0; i < r; i++)
    {
        CAR *c = new CAR;
        X = rand() % 137 + 205;
        Y = (rand()%67 + 37) * -1;
        c->setPosition(X, Y);
        enemigos.push_back(c);
    }

}

void Game::desplazar()
{
    int coun = 0, counA = 0;
    vector<Arbol*>::iterator i = arboles.begin();
    for (i = arboles.begin(); i != arboles.end(); i++)
    {
        (*i)->desplazar(7);
        if((*i)->getPosY() > 419)
            counA += 1;
    }

    vector<CAR*>::iterator j = enemigos.begin();
    for (j = enemigos.begin(); j != enemigos.end(); j++)
    {
        (*j)->desplazar(5);
        if((*j)->getPosY() > 419)
            coun += 1;
    }

    if(clock.getElapsedTime().asSeconds() > 1.5)
    {
        addEnemy();
        clock.restart();
    }

    if(coun > 0)
    {
        delete(*enemigos.begin());
        enemigos.erase(enemigos.begin());
    }
    if(counA > 0)
    {
        delete(*arboles.begin());
        arboles.erase(arboles.begin());
        addArbol();
    }
    ///llegaste?
    marca.subir(0.2);
    if(marca.getPosY() <= marca.getLimit()) gameOver = true;

    miCar.velocidad(clockGame);
    clockGame.restart();

}

string Game::to_string(float f)
{
    stringstream ss (stringstream::in | stringstream::out);
    ss << f;
    string test = ss.str();
    return test;
}

void Game::draw()
{
    m_renderWindow->draw(sBG);

    sf::Sprite aux;
    vector<Arbol*>::iterator i = arboles.begin();
    for (i = arboles.begin(); i != arboles.end(); i++)
    {
        aux = (*i)->getSprite();
        aux.move((*i)->getPosX(), (*i)->getPosY());
        m_renderWindow->draw(aux);
    }

    vector<CAR*>::iterator j = enemigos.begin();
    for (j = enemigos.begin(); j != enemigos.end(); j++)
    {
        aux = (*j)->getSprite();
        aux.move((*j)->getPosX(), (*j)->getPosY());
        m_renderWindow->draw(aux);
    }

    aux = miCar.getSprite();
    aux.move(miCar.getPosX(), miCar.getPosY());
    m_renderWindow->draw(aux);

    aux = marca.getSprite();
    aux.move(marca.getPosX(), marca.getPosY());
    m_renderWindow->draw(aux);


    ///-----------------------------------------------------

    sf::Font font;
    font.loadFromFile("fonts/Anonymous.ttf");
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    ///Tiempo
    text.setString(to_string(miCar.getTiempo()) + " s");
    text.setCharacterSize(15);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width/2,textRect.height/2);
    text.setPosition(sf::Vector2f(450,60));
    m_renderWindow->draw(text);
    ///Velocidad
    text.setString(to_string(miCar.getVelocidad()) + " km/h");
    text.setCharacterSize(15);

    sf::FloatRect textRect1 = text.getLocalBounds();
    text.setOrigin(textRect1.width/2,textRect1.height/2);
    text.setPosition(sf::Vector2f(450,120));
    m_renderWindow->draw(text);

}

void Game::colision()
{
    int SepEjeX, SepEjeY;
    vector<CAR*>::iterator j = enemigos.begin();
    for(j = enemigos.begin(); j != enemigos.end(); *j++)
    {
        SepEjeY = miCar.getPosY() - ((*j)->getPosY()) - 36;

        if((*j)->getPosX() <= miCar.getPosX())  ///Evaluando lado IZQUIERDO
            SepEjeX = miCar.getPosX() - ((*j)->getPosX()) - 18;

        else                                    ///Evaluando lado DERECHO
            SepEjeX = ((*j)->getPosX()) - miCar.getPosX() - 21;

        if(SepEjeX <= 0 && SepEjeY <=0)         ///Evaluando si hay separacion entre ellos
        {
            gameOver = true;
            miCar.cargarBoom();
            break;
        }
    }
}

void Game::win()
{
    ///************************** Draw BG **************************************************
    sf::Texture textureBG;
    textureBG.loadFromFile("Sprite/winner.png");
    sf::Sprite sprite(textureBG);

    ///************************* Draw words ************************************************
    sf::Texture tWords;
    tWords.loadFromFile("Sprite/ganaste.png");
    sf::Sprite sWords(tWords, sf::IntRect(0, 0, 400, 47));
    sWords.setScale(sf::Vector2f(0.5f, 0.5f)); //200x22
    sWords.move(157.5, 180); //257.5 - (200 / 2) = 157.5

    ///************************* Draw Emoji ************************************************

    sf::Texture tEmoji;
    //tEmoji.loadFromFile("Sprite/Emojis/cool.png");
    tEmoji.loadFromFile("Sprite/Emojis/wow.png");
    sf::Sprite sEmoji(tEmoji, sf::IntRect(0, 0, 500, 500));
    sEmoji.setScale(sf::Vector2f(0.08f, 0.08f)); //37x37
    sEmoji.move(239, 220); //257.5 - (37 / 2) = 239

    m_renderWindow->draw(sprite);
    m_renderWindow->draw(sWords);
    m_renderWindow->draw(sEmoji);
}

void Game::loser()
{
    ///************************** Draw BG **************************************************
    sf::Texture textureBG;
    textureBG.loadFromFile("Sprite/loser.png");
    sf::Sprite sprite(textureBG);

    ///************************* Draw words ************************************************
    sf::Texture tWords;
    tWords.loadFromFile("Sprite/perdiste.png");
    sf::Sprite sWords(tWords, sf::IntRect(0, 0, 400, 44));
    sWords.setScale(sf::Vector2f(0.5f, 0.5f)); //200x22
    sWords.move(157.5, 180); //257.5 - (200 / 2) = 157.5
    /*sf::Font font;
    font.loadFromFile("fonts/Anonymous.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("PERDISTE   ");
    text.setCharacterSize(24);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width/2,textRect.height/2);
    text.setPosition(Vector2f(515/2.0f, 420/2.0f));*/

    ///************************* Draw Emoji ************************************************

    sf::Texture tEmoji;
    tEmoji.loadFromFile("Sprite/Emojis/jajaja.png");
    sf::Sprite sEmoji(tEmoji, sf::IntRect(0, 0, 74, 74));
    sEmoji.setScale(sf::Vector2f(0.5f, 0.5f)); //37x37
    sEmoji.move(239, 220); //257.5 - (37 / 2) = 239

    m_renderWindow->draw(sprite);
    m_renderWindow->draw(sWords);
    m_renderWindow->draw(sEmoji);
}

void Game::clean()
{
    vector<Arbol*>::iterator i;
    for (i = arboles.begin(); i != arboles.end(); i++)
        delete(*i);
    arboles.clear();
    vector<CAR*>::iterator j;
    for (j = enemigos.begin(); j != enemigos.end(); j++)
        delete(*j);
    enemigos.clear();
}

void Game::start()
{
    while(m_renderWindow->isOpen())
    {
        sf::Event event;
        while (m_renderWindow->pollEvent(event))
        {   //este while sirve para comprobar si doy en x para cerrar la ventana y cerrarla
            if (event.type == sf::Event::EventType::Closed)
            {
                m_renderWindow->close();
                clean();
            }
            else if(event.type == sf::Event::KeyPressed)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) miCar.moveLeft();
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) miCar.moveRight();
            }
        }
        if(gameOver)
        {
            if(marca.getPosY() <= marca.getLimit())
            {
                m_renderWindow->clear();
                draw();
                win();
                m_renderWindow->display();
            }
            else
            {
                if(miCar.rBoom.left < float(miCar.tBoom.getSize().x))
                {
                    miCar.invisible();
                    m_renderWindow->draw(miCar.getSpriteBoom());
                    draw();
                    m_renderWindow->display();
                    miCar.boom();
                }
                else
                {
                    m_renderWindow->clear();
                    draw();
                    loser();
                    m_renderWindow->display();
                }
            }
        }

        else
        {
            colision();
            desplazar();
            m_renderWindow->clear();
            draw();
            m_renderWindow->display();
        }
    }
}
