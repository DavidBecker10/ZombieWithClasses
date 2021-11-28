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
        goLeaderboard,
        resume,
        saveGame,
        onePlayer,
        twoPlayer,
        goSubway
    };

    class ScreenManager : public States::StateMachine {
    private:
        GraphicManager* GM;
        bool twoPlayers;
        //Entities::Characters::Player *player1;

    public:
        ScreenManager(GraphicManager* gm/*, Entities::Characters::Player *p1 = nullptr*/);

    protected:
        bool processCode(int returnCode) override;
    };
}

#endif //ZOMBIEWITHCLASSES_SCREENMANAGER_H
