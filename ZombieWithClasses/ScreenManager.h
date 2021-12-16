#ifndef ZOMBIEWITHCLASSES_SCREENMANAGER_H
#define ZOMBIEWITHCLASSES_SCREENMANAGER_H

#include"StateMachine.h"
#include "Player.h"

namespace Managers {

    class GraphicManager;

    enum returnCode {
        proceed,
        end,
        goRacoonCity,
        loadGame,
        goMainMenu,
        goPauseMenu,
        resume,
        saveGame,
        onePlayer,
        twoPlayer,
        goSubway,
        goLeaderBoard,
        goEndGame
    };

    class ScreenManager : public States::StateMachine {
    private:
        GraphicManager* GM;
        bool twoPlayers;
        Entities::Characters::Player* player1;

    public:
        ScreenManager(GraphicManager* gm);

    protected:
        bool processCode(int returnCode) override;
    };
}

#endif //ZOMBIEWITHCLASSES_SCREENMANAGER_H
