#include "ScreenManager.h"
#include "PlayerOne.h"
#include "Stage.h"
#include "RacoonCity.h"
#include "Subway.h"
#include "MainMenuState.h"
#include "PauseMenuState.h"
#include <fstream>
using namespace Managers;

ScreenManager::ScreenManager(GraphicManager* gm, Entities::Characters::PlayerOne* p1) :
    GM{ gm },
    player1{ p1 },
    numPlayers{false}
{
    push(new States::MainMenuState(*GM));
}

bool ScreenManager::processCode(int returnCode) {
    switch (returnCode) {
    case end:
        return true;
    case goRacoonCity: {
        auto* racoon = new States::RacoonCity(GM, this, new Entities::Characters::PlayerOne(Vector2F(100.0f, 3000.0f)));
        racoon->initialize(numPlayers);
        push(racoon);
        return false;
    }
    case goSubway: {
        auto* subway = new States::Subway(GM, this, new Entities::Characters::PlayerOne(Vector2F(100.0f, 3000.0f)));
        subway->initialize(numPlayers);
        push(subway);
        return false;
    }
    case saveGame: {
        pop();
        States::Stage* s = dynamic_cast<States::Stage*>(top());
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
            States::RacoonCity* stage = new States::RacoonCity(GM, this, new Entities::Characters::PlayerOne());
            try {
                stage->load("../saves/saves.json");
                push(stage);
            }
            catch (char const* s) {
                std::cout << s << std::endl;
                delete stage;
            }
        }
        else {
            States::Subway* stage = new States::Subway(GM, this, new Entities::Characters::PlayerOne());
            try {
                stage->load("../saves/saves.json");
                push(stage);
            }
            catch (char const* s) {
                std::cout << s << std::endl;
                delete stage;
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
    }
    case onePlayer: {
        numPlayers = false;
        return false;
    }
    case twoPlayers: {
        numPlayers = true;
        return false;
    }
    case proceed:
    default:
        return false;
    }
}
