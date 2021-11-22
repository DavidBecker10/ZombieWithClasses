#include "Game.h"
#include "Tile.h"

Game::Game() :
    player1(Entities::Characters::Player(sf::Vector2f(20.0f, 20.0f), sf::Vector2f(0.0f, 0.0f), Ids::Ids::Player)),
    SM(&GM, &player1),
    end(false)
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
        end = !(GM.getWindow()->isOpen());
        GM.show();
    }
}
