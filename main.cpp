#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "GAME.h"

int main()
{
    srand((unsigned)time(0));
    sf::RenderWindow renderWindow(sf::VideoMode(515, 420), "Demo Game", sf::Style::Close);
    renderWindow.setFramerateLimit(60);

    Game game(renderWindow);
	game.start();
    return EXIT_SUCCESS;
}

