#include "RacoonCity.h"
#include "Homer.h"
#include "Ghoul.h"
#include "Lava.h"
using namespace States;
#include "Tile.h"
#include <fstream>
#include "Ids.h"
#include "Nemesis.h"
RacoonCity::RacoonCity(Managers::GraphicManager* gm, Entities::Characters::Player* p1) :
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
                  {32.0f, 32.0f}, RACOON_PATH
          },
          p1 } {

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
            auto* Enemy = new Entities::Characters::Homer(e["position"], e["life"], player1);
            EL.insert(Enemy);
            break;
        }
        case Ids::Ids::Ghoul: {
            auto* Enemy = new Entities::Characters::Ghoul(e["position"], e["life"], player1);
            EL.insert(Enemy);
            break;
        }
                            //            case Ids::Ids::Nemesis: {
                            //                EL.insert(new Entities::Characters::Nemesis(e, player1));
                            //                break;
                            //            }
        case Ids::Ids::Bullet: {
            EL.insert(new Entities::Bullet(e));
        }
                             //            case Ids::Ids::Bone: {
                             //                EL.insert(new Entities::Bone(e));
                             //            }
        default:
            break;
        }
    }

    EL.initialize(GM, &EM, &CM);
}

void RacoonCity::initialize(bool twoPlayers) {
    srand(time(NULL));
    if (player1) EL.insert(player1);
    player1->setEL(&EL);
    player1->setStage(1);

    if (twoPlayers)
    {
        player2 = new Entities::Characters::PlayerTwo(Vector2F(200, 3040));
        EL.insert(player2);
    }
    int i = (rand() % 2) + 3;
    //EL.insert(new Entities::Characters::Nemesis(Vector2F(1000.f, 3080.f), player1));
    EL.insert(new Entities::Characters::Homer(Vector2F(850.f, 2780.f), player1));
    while (i > 0) {
        EL.insert(new Entities::Characters::Homer(Vector2F(((rand() % 530 + 100) * 10.0f), 3040.f), player1));
        EL.insert(new Entities::Characters::Ghoul(Vector2F(((rand() % 530 + 100) * 10.0f), 3040.f), player1));
        i--;
    }

    EL.initialize(GM, &EM, &CM);

}
