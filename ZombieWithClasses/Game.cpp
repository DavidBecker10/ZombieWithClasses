#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game() :
    GM(),
    EM(),
    close(false),
    clock(),
    Player1(Vector2F(0.f, 0.f), Vector2F(0.0f, 0.0f), "../Sprites/Terrorists/Muslim/Attack1/Attack1_1.png"),
    Player2(Vector2F(0.f, 0.f), Vector2F(0.0f, 0.0f), "../Sprites/Terrorists/Masked/Attack1/Attack1_1.png"),
    EntityL()
{
    EntityL.insert(static_cast<Entities::Entity*>(&Player1));
    EntityL.insert(static_cast<Entities::Entity*>(&Player2));
    execute();
}

Game::~Game()
{
}

void Game::execute()
{
    EM.setCharacter(&Player1, &Player2);
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

        EntityL.initialize(GM);
        GM.center(Player1.getPosition());
        GM.clear();
        GM.initializeView();
        EntityL.update(t);
        EntityL.draw(GM);
        GM.show();
    }
    
}
