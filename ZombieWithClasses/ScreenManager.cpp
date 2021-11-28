#include "ScreenManager.h"
#include "Stage.h"
#include "RacoonCity.h"
#include "MainMenuState.h"
#include "PauseMenuState.h"
#include <fstream>
#include "Subway.h"
#include "stdafx.h"
using namespace Managers;

ScreenManager::ScreenManager(GraphicManager* gm/*, Entities::Characters::Player *p1*/) :
    GM{ gm }, twoPlayers(false)/*, player1{p1}*/ {
    push(new States::MainMenuState(*GM));
}

bool ScreenManager::processCode(int returnCode) {
    switch (returnCode) {
    case end:
        return true;
    case goRacoonCity: {
        auto* player1 = new Entities::Characters::Player(Vector2F(100.0f, 3040.0f));
        auto* racoon = new States::RacoonCity(GM, player1);
        racoon->initialize(twoPlayers);
        push(racoon);
        return false;
    }
    case goSubway: {
        auto* player1 = new Entities::Characters::Player(Vector2F(100.0f, 3040.0f));
        auto* subway = new States::Subway(GM, player1);
        subway->initialize(twoPlayers);
        push(subway);
        return false;
    }
    case saveGame: {
        pop();
        auto* s = dynamic_cast<States::Stage*>(top());
        if (!s)
            std::cout << "No stage to save" << std::endl;
        else if (!s->save("../saves/saves.json")) std::cout << "Error. Game can't be saved" << std::endl;
        return false;
    }
    case loadGame: {
        std::ifstream file("../saves/saves.json");
        if (file.fail()) throw "path not found!";
        nlohmann::json j;
        file >> j;
        int a;

        j = j["Entity"][0];
        a = static_cast<int>(j["Stage"]);

        if (a == 1) {
            auto* player1 = new Entities::Characters::Player();
            auto* rc = new States::RacoonCity(GM, player1);
            //States::RacoonCity* stage = new States::RacoonCity(GM, new Entities::Characters::Player());
            try {
                rc->load("../saves/saves.json");
                push(rc);
            }
            catch (char const* s) {
                std::cout << s << std::endl;
                delete rc;
            }
        }
        else {
            auto* player1 = new Entities::Characters::Player();
            auto* sw = new States::Subway(GM, player1);
            //States::Subway* stage = new States::Subway(GM, this, new Entities::Characters::PlayerOne());
            try {
                sw->load("../saves/saves.json");
                push(sw);
            }
            catch (char const* s) {
                std::cout << s << std::endl;
                delete sw;
            }
        }

        return false;
    }
    case goPauseMenu: {
        push(new States::PauseMenuState(*GM));
        return false;
    }
    case resume: {
        pop();
        return false;
    }
    case goMainMenu: {
        emptyStack();
        push(new States::MainMenuState(*GM));
        return false;
    }
    case onePlayer: {
        twoPlayers = false;
        return false;
    }
    case twoPlayer: {
        twoPlayers = true;
        return false;
    }
    case proceed:
    default:
        return false;
    }
}