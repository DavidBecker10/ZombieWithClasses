#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game():
GM(),
close(false),
Player(Vector2F(0.f, 0.f), Vector2F(2.0f, 2.0f), "walk6.png")
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
        clock.restart();
        float t = clock.getElapsedTime().asSeconds();
        
        EM.setWindow(GM.getWindow());
        while (EM.checkEvent())
        {
            if (EM.handleEvent())
                close = true;
        }

        Player.initialize(GM);
        GM.clear();
        Player.update(t);
        Player.draw(GM);
        GM.show();

    }
    
}
