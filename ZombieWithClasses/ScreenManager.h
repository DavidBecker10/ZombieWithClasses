#pragma once
#include "StateMachine.h"
#include "Player.h"

namespace Managers {

    class GraphicManager;

    enum returnCode {
        proceed,
        end,
        goRacoonCity,
        goSecondStage,
    };

    class ScreenManager :
        public States::StateMachine
    {
    private:
        GraphicManager* GM;
        Entities::Characters::Player* player1;

    public:
        ScreenManager(GraphicManager* gm, Entities::Characters::Player* p1 = nullptr);

    protected:
        bool processCode(int returnCode) override;
    };
}