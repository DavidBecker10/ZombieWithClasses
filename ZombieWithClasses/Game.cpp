#include "Game.h"
#include <SFML/Graphics.hpp>
#include "CollisionManager.h"

Game::Game() :
    GM(),
    EM(),
    CM(),   
    TM{
        {
            new Entities::Tile(Ids::empty, "../Sprites/Tiles/Empty.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_01.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground2, "../Sprites/Tiles/Platformer/Ground_02.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground3, "../Sprites/Tiles/Platformer/Ground_03.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground4, "../Sprites/Tiles/Platformer/Ground_04.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground5, "../Sprites/Tiles/Platformer/Ground_05.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground6, "../Sprites/Tiles/Platformer/Ground_06.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground7, "../Sprites/Tiles/Platformer/Ground_07.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground8, "../Sprites/Tiles/Platformer/Ground_08.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground9, "../Sprites/Tiles/Platformer/Ground_09.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground10, "../Sprites/Tiles/Platformer/Ground_10.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground11, "../Sprites/Tiles/Platformer/Ground_11.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground12, "../Sprites/Tiles/Platformer/Ground_12.png", {32.0f, 32.0f}),
            new Entities::Tile(Ids::ground13, "../Sprites/Tiles/Platformer/Ground_13.png", {32.0f, 32.0f}),
        },
        { 50.0f, 50.0f }, "map.json"
    },
    close(false),
    clock(),
    EntityL(),
    IDwindowclosed{ EM.addListenOthers([this](const sf::Event& e) {isWindowClosed(e); }) }
{
    EntityL.insert(new Entities::Characters::Player(Vector2F(200.f, 200.f), Vector2F(0.f, 0.f), Ids::Player, "../Sprites/Terrorists/Muslim/Attack1/Attack1_1.png"));
    EntityL.insert(new Entities::Characters::Enemy(Vector2F(210.f, 210.f), Vector2F(0.f, 0.f), Ids::Enemy, "../Sprites/Zombies/ZombieWoman/animation/Attack1.png"));
    
    EntityL.initialize(&GM, &EM);

    TM.initialize(&GM, &EM);
    
    EM.setWindow(GM.getWindow());

    CM.setTilesManager(&TM);

    CM.setList(&EntityL);

    execute();
}

Game::~Game()
{
    EntityL.destroyEntities();
}

void Game::execute()
{
    clock.restart();
    while (!close)
    {
        float t = clock.getElapsedTime().asSeconds();
        clock.restart();

        GM.clear();
        EntityL.update(t);
        CM.verifyCollisions();
        TM.draw(GM);
        EntityL.draw(&GM);
        EM.manageEvent();

        GM.show();
    }
    
}

void Game::isWindowClosed(const sf::Event& e)
{   
    if (e.type == sf::Event::Closed) close = true;
}