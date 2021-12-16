#include "Subway.h"
#include "Homer.h"
#include "Ghoul.h"
#include "Tile.h"
#include <fstream>
#include <time.h>
#include <random>
#include "Ids.h"
#include "stdafx.h"
#include "Nemesis.h"
#include "Bullet.h"
#include "Platform.h"
#include "Fire.h"
#include "SpiderWeb.h"
#include "Lava.h"

States::Subway::Subway(Managers::GraphicManager* gm, Entities::Characters::Player* p1) :
    Stage{ gm,
           new Managers::TilesManager{
                   {
                           new Tiles::Tile(Ids::air, "../assets/Tiles/Platformer/Air.png", {32.0f, 32.0f}),
                           new Tiles::Tile(Ids::empty, "../assets/Tiles/Platformer/Empty.png", {32.0f, 32.0f}),
                           new Tiles::Tile(Ids::ground, "../assets/Tiles/Platformer/Ground_02.png", {32.0f, 32.0f}),
                           new Tiles::Tile(Ids::dirt, "../assets/Tiles/Platformer/Ground_06.png", {32.0f, 32.0f}),
                           new Tiles::Platform(),
                           new Tiles::SpiderWeb(),
                           new Tiles::Fire(),
                           new Tiles::Lava(),
                           new Tiles::Tile(Ids::wallL, "../assets/Tiles/Platformer/WallL.png", {32.0f, 32.0f}),
                           new Tiles::Tile(Ids::wallR, "../assets/Tiles/Platformer/WallR.png", {32.0f, 32.0f}),
                   },
                   {32.0f, 32.0f}, SUBWAY_PATH
           },
           p1 }
{
    player1->setScore(0);
}

nlohmann::json States::Subway::convertJSON()
{
    nlohmann::json js;

    js["Entity"] = EL.convertJSON();

    return js;
}

void States::Subway::load(const std::string& path)
{
    std::ifstream file(path);
    TM->regenTiles();
    if (file.fail()) throw "path not found!";
    nlohmann::json j;
    file >> j;

    for (nlohmann::json e : j["Entity"]) {
        switch (static_cast<int>(e["ID"])) {
        case Ids::Ids::Player: {
            if (player1) {
                player1->initializeJSON(e);
                EL.insert(player1);
            }
            break;
        }
        case Ids::Ids::Player2: {
            if (player2) {
                player2->initializeJSON(e);
                EL.insert(player2);
            }
            else
            {
                player2 = new Entities::Characters::PlayerTwo();
                player2->initializeJSON(e);
                EL.insert(player2);
            }
            break;
        }
        case Ids::Ids::Homer: {
            EL.insert(new Entities::Characters::Homer(e["position"], e["life"], player1, player2));
            break;
        }
        case Ids::Ids::Ghoul: {
            EL.insert(new Entities::Characters::Ghoul(e["position"], e["life"], player1, player2));
            break;
        }
        case Ids::Ids::Nemesis: {
            EL.insert(new Entities::Characters::Nemesis(e["position"], e["life"], player1, player2));
            break;
        }
        case Ids::Ids::Bullet: {
            EL.insert(new Entities::Bullet(e["position"], e["vel"], e["dir"]));
            break;
        }
        case Ids::Ids::Rock: {
            EL.insert(new Entities::Rock(e["position"], e["vel"], e["dir"]));
            break;
        }
        case Ids::Ids::Bone: {
            EL.insert(new Entities::Bone(e["position"], e["vel"], e["dir"]));
            break;
        }
        default:
            break;
        }
    }

    EL.initialize(GM, &EM, &CM);
}

void States::Subway::initialize(bool twoPlayers)
{
    srand(time(NULL));
    if (player1) EL.insert(player1);
    player1->setEL(&EL);
    player1->setStage(2);
    player1->setScore(playerScore);
    player2 = nullptr;
    if (twoPlayers)
    {
        player2 = new Entities::Characters::PlayerTwo(Vector2F(200, 1450));
        EL.insert(player2);
    }


    int i = (rand() % 2) + 3;
    while (i > 0) {
        EL.insert(new Entities::Characters::Homer(Vector2F((((rand() % 430) + 100) * 10.0f), 1450.f), player1, player2));
        EL.insert(new Entities::Characters::Ghoul(Vector2F((((rand() % 430) + 100) * 10.0f), 1450.f), player1, player2));
        i--;
    }

    EL.insert(new Entities::Characters::Nemesis(Vector2F(6300, 1380), player1, player2));

    EL.initialize(GM, &EM, &CM);

}