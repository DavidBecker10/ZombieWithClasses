#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game():
GM(),
close(false),
Player(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.02f, 0.02f), "walk6.png")
{
    execute();
}

Game::~Game()
{
}

void Game::execute()
{
    while (!close)
    {
        EM.setWindow(GM.getWindow());
        while (EM.checkEvent())
        {
            if (EM.handleEvent())
                close = true;
        }

        Player.initialize(GM);
        Player.draw(GM);
        GM.show();
        GM.clear();
        Player.move(1.2);
    }
    
}
