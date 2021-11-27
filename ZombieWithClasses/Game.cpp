#include "Game.h"
#include "Tile.h"

Game::Game() :
    SM(&GM),
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
