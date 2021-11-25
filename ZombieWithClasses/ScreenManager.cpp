#include "ScreenManager.h"
#include "Stage.h"
#include "RacoonCity.h"
#include "MainMenuState.h"
#include "PauseMenuState.h"
using namespace Managers;

ScreenManager::ScreenManager(GraphicManager* gm, Entities::Characters::Player* p1) :
    GM{ *gm }, player1{ p1 } {
    push(new States::MainMenuState(GM));
}

bool ScreenManager::processCode(int returnCode) {
    switch (returnCode) {
    case end:
        return true;
    case goRacoonCity: {
        auto* racoon = new States::RacoonCity(&GM, player1);
        racoon->initialize();
        push(racoon);
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
        States::RacoonCity* rc = new States::RacoonCity(&GM, player1);
        try {
            rc->load("../saves/saves.json");
            push(rc);
        }
        catch (char const* s) {
            std::cout << s << std::endl;
            delete rc;
        }
        return false;
    }
    case goPauseMenu: {
        push(new States::PauseMenuState(GM));
        return false;
    }
    case resume: {
        pop();
        return false;
    }
    case goMainMenu: {
        emptyStack();
        push(new States::MainMenuState(GM));
        return false;
    }

    case proceed:
    default:
        return false;
    }
}
