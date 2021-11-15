#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game() :
    GM(),
    EM(),
    CM(),
    TM{
        {
            new Tile(Ids::empty, "../Sprites/Tiles/Empty.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_01.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_02.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_03.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_04.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_05.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_06.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_07.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_08.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_09.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_10.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_11.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_12.png", {32.0f, 32.0f}),
            new Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_13.png", {32.0f, 32.0f}),
        },
        (32.0f, 32.0f), "../Sprites/map.json"
    },
    close(false),
    clock(),
    Player1(Vector2F(150.f, 0.f), Vector2F(0.0f, 0.0f), "../Sprites/Terrorists/Muslim/Attack1/Attack1_1.png"),
    Player2(Vector2F(300.f, 0.f), Vector2F(0.0f, 0.0f), "../Sprites/Terrorists/Masked/Attack1/Attack1_1.png"),
    Zombie(Vector2F(0.f, 0.f), Vector2F(20000.0f, 0.0f), "../Sprites/Zombies/ZombieWoman/Animation/Attack1.png"),
    EntityL()
{
    EntityL.insert(static_cast<Entities::Entity*>(&Player1));
    EntityL.insert(static_cast<Entities::Entity*>(&Player2));
    EntityL.insert(static_cast<Entities::Entity*>(&Zombie));
    TM.initialize(GM, EM);
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
        GM.center(Vector2F(100.f, 100.f));
        CM.checkCollision(EntityL);
        GM.clear();
        GM.initializeView();
        EntityL.update(t);
        EntityL.draw(GM);
        GM.show();
    }
    
}