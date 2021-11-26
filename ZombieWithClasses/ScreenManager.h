#ifndef ZOMBIEWITHCLASSES_SCREENMANAGER_H
#define ZOMBIEWITHCLASSES_SCREENMANAGER_H

#include"StateMachine.h"
#include "PlayerOne.h"

namespace Managers {

    class GraphicManager;

    enum returnCode {
        proceed,
        end,
        goRacoonCity,
        loadGame,
        goSecondStage,
        goMainMenu,
        goPauseMenu,
        resume,
        saveGame,
        onePlayer,
        twoPlayers
    };

    class ScreenManager : public States::StateMachine {
    private:
        GraphicManager GM;
        Entities::Characters::PlayerOne* player1;
        bool numPlayers;

    public:
        ScreenManager(GraphicManager* gm, Entities::Characters::PlayerOne* p1 = nullptr);
        bool processCode(int returnCode) override;
    };
}

#endif //ZOMBIEWITHCLASSES_SCREENMANAGER_H
