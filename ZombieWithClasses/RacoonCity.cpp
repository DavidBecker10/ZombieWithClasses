#include "RacoonCity.h"
#include "Homer.h"
#include "Ghoul.h"
#include "Lava.h"
#include "Tile.h"
#include <fstream>
#include "Ids.h"
#include "stdafx.h"

using namespace States;

RacoonCity::RacoonCity(Managers::GraphicManager* gm, Managers::ScreenManager* sm, Entities::Characters::PlayerOne* p1) :
    Stage{ gm,
          new Managers::TilesManager{
                  {
                          new Entities::Tile(Ids::empty, "../assets/Tiles/Platformer/Empty.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::air, "../assets/Tiles/Platformer/Air.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground1, "../assets/Tiles/Platformer/Ground_01.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground2, "../assets/Tiles/Platformer/Ground_02.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground3, "../assets/Tiles/Platformer/Ground_03.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground4, "../assets/Tiles/Platformer/Ground_04.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground5, "../assets/Tiles/Platformer/Ground_05.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground6, "../assets/Tiles/Platformer/Ground_06.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground7, "../assets/Tiles/Platformer/Ground_07.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground8, "../assets/Tiles/Platformer/Ground_08.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground9, "../assets/Tiles/Platformer/Ground_09.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground10, "../assets/Tiles/Platformer/Ground_10.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground11, "../assets/Tiles/Platformer/Ground_11.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::ground12, "../assets/Tiles/Platformer/Ground_12.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::wallL, "../assets/Tiles/Platformer/WallL.png", {32.0f, 32.0f}),
                          new Entities::Tile(Ids::wallR, "../assets/Tiles/Platformer/WallR.png", {32.0f, 32.0f}),
                          new Lava,
                  },
                  {32.0f, 32.0f}, "../assets/Maps/mapStage1.json"
          }, sm,
          p1 }
{

}

nlohmann::json RacoonCity::convertJSON() {
    nlohmann::json js;

    js["Entity"] = EL.convertJSON();

    return js;
}

void RacoonCity::load(const std::string& path) {
    std::ifstream file(path);

    if (file.fail()) throw "path not found!";
    nlohmann::json j;
    file >> j;

    for (nlohmann::json e : j["Entity"]) {
        switch (static_cast<int>(e["ID"])) {
        case Ids::Ids::Player1: {
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
        case Ids::Ids::Enemy: {
            EL.insert(new Entities::Characters::Homer(e));
            break;
        }
        case Ids::Ids::Homer: {
            EL.insert(new Entities::Characters::Homer(e));
            break;
        }
        case Ids::Ids::Ghoul: {
            EL.insert(new Entities::Characters::Ghoul(e));
            break;
        }
        default:
            break;
        }
    }

    EL.initialize(GM, &EM, &CM);
}

void RacoonCity::initialize(bool numPlayers) {

    srand(time(NULL));
    if (player1) EL.insert(player1);
    player1->setEL(&EL);
    player1->setStage(1);

    if (numPlayers)
    {
        player2 = new Entities::Characters::PlayerTwo(Vector2F(200, 3000));
        EL.insert(player2);
    }
    //player1->setPlayer2(player2);
    
    Vector2F pos = { 500.0f, 3000.0f };
    Vector2F vel = { 50.0f, 0.0f };

    for (int i = 0; i < rand() % 7 + 3; i++)
    {
        EL.insert(new Entities::Characters::Homer(Vector2F(pos), Vector2F(-50.0f, 0.0f)));
        //EL.insert(new Entities::Characters::Ghoul(Vector2F(500.f, 3000.f), Vector2F(50.0f, 0.0f)));
        //EL.insert(new Entities::Characters::Ghoul(Vector2F(1650.f, 3000.f), Vector2F(50.0f, 0.0f)));
        pos.x += 800.0f;
        pos.y -= 300.0f;
        EL.initialize(GM, &EM, &CM);
    }
}