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
            new Tile(Ids::ground2, "../Sprites/Tiles/Platformer/Ground_02.png", {32.0f, 32.0f}),
            new Tile(Ids::ground3, "../Sprites/Tiles/Platformer/Ground_03.png", {32.0f, 32.0f}),
            new Tile(Ids::ground4, "../Sprites/Tiles/Platformer/Ground_04.png", {32.0f, 32.0f}),
            new Tile(Ids::ground5, "../Sprites/Tiles/Platformer/Ground_05.png", {32.0f, 32.0f}),
            new Tile(Ids::ground6, "../Sprites/Tiles/Platformer/Ground_06.png", {32.0f, 32.0f}),
            new Tile(Ids::ground7, "../Sprites/Tiles/Platformer/Ground_07.png", {32.0f, 32.0f}),
            new Tile(Ids::ground8, "../Sprites/Tiles/Platformer/Ground_08.png", {32.0f, 32.0f}),
            new Tile(Ids::ground9, "../Sprites/Tiles/Platformer/Ground_09.png", {32.0f, 32.0f}),
            new Tile(Ids::ground10, "../Sprites/Tiles/Platformer/Ground_10.png", {32.0f, 32.0f}),
            new Tile(Ids::ground11, "../Sprites/Tiles/Platformer/Ground_11.png", {32.0f, 32.0f}),
            new Tile(Ids::ground12, "../Sprites/Tiles/Platformer/Ground_12.png", {32.0f, 32.0f}),
            new Tile(Ids::ground13, "../Sprites/Tiles/Platformer/Ground_13.png", {32.0f, 32.0f}),
        },
        {32.0f, 32.0f }, "map.json"
    },
    close(false),
    clock(),
    Player1(Vector2F(0.f, 100.f), Vector2F(0.0f, 0.0f), "../Sprites/Terrorists/Muslim/Attack1/Attack1_1.png"),
    Player2(Vector2F(200.f, 100.f), Vector2F(0.0f, 0.0f), "../Sprites/Terrorists/Masked/Attack1/Attack1_1.png"),
    Zombie(Vector2F(100.f, 100.f), Vector2F(20000.0f, 0.0f), "../Sprites/Zombies/ZombieWoman/Animation/Attack1.png"),
    EntityL(),
    IDwindowclosed{ EM.addListenOthers([this](const sf::Event& e) {isWindowClosed(e); }) }
{
    EntityL.insert(static_cast<Entities::Entity*>(&Player1));
    EntityL.insert(static_cast<Entities::Entity*>(&Player2));
    EntityL.insert(static_cast<Entities::Entity*>(&Zombie));

    TM.initialize(GM, EM);

    //std::vector<Tile*> tiles = TM.getTiles();
    /*
    for (int i = 0; i < tiles.size(); i++)
        EntityL.insert(dynamic_cast<Entities::Entity*>(tiles[i]));
    */
    
    EM.setWindow(GM.getWindow());
    execute();
}

Game::~Game()
{
}

void Game::execute()
{

    //std::vector<Tile*> tiles = TM.getTiles();
    //EM.setCharacter(&Player1, &Player2);
    clock.restart();
    while (!close)
    {
        float t = clock.getElapsedTime().asSeconds();
        clock.restart();

        EM.manageEvent();

        GM.clear();
        EntityL.update(t);
        EntityL.initialize(GM);
        //CM.checkCollision(EntityL);
        //EntityL.draw(GM);
        TM.draw(GM);
        //GM.centralize(Vector2F(100.f, 100.f));
        //GM.initializeView();

        GM.show();
    }
    
}

void Game::isWindowClosed(const sf::Event& e) {
    if (e.type == sf::Event::Closed) close = true;
}