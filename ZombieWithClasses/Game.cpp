#include "Game.h"
#include "Tile.h"

Game::Game() :
    player1(Entities::Characters::PlayerOne(Vector2F(100.0f, 3000.0f))),
    SM(&GM, &player1),
    end{ false }
{
    execute();
}
Game::~Game()
{

}

void Game::execute()
{
    while (!end) {
        GM.clear();
        end = SM.execute();
        GM.show();
    }
}
