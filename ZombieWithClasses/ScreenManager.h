#ifndef ZOMBIEWITHCLASSES_SCREENMANAGER_H
#define ZOMBIEWITHCLASSES_SCREENMANAGER_H

#include"StateMachine.h"
#include "PlayerOne.h"
#include "PlayerTwo.h"

namespace Managers {

    class GraphicManager;

    enum returnCode {
        proceed,
        end,
        goRacoonCity,
        goSecondStage,
    };

    class ScreenManager : public States::StateMachine {
    private:
        GraphicManager GM;
        Entities::Characters::PlayerOne* player1;
        Entities::Characters::PlayerTwo* player2;

    public:
        ScreenManager(GraphicManager* gm, Entities::Characters::PlayerOne* p1 = nullptr, Entities::Characters::PlayerTwo* p2 = nullptr);

    protected:
        bool processCode(int returnCode) override;
    };
}

#endif //ZOMBIEWITHCLASSES_SCREENMANAGER_H
