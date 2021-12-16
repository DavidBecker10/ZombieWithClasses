#ifndef ZOMBIEWITHCLASSES_STAGE_H
#define ZOMBIEWITHCLASSES_STAGE_H

#include "State.h"
#include "PlayerTwo.h"
#include "CollisionManager.h"
#include "Save.h"
#include "Clock.h"

namespace States {
    class Stage :public State, public Save {
    protected:
        Entities::Characters::Player* player1;
        Entities::Characters::PlayerTwo* player2;

        Managers::GraphicManager* GM;
        Managers::EventManager EM;
        Managers::CollisionManager CM;
        Managers::TilesManager* TM;

        Clock clock;
        Lists::EntityList EL;

        int returnCode;
        static int playerScore;
        void setReturnCode(int rc) { returnCode = rc; }


    private:

        unsigned int IDCloseScreen;
        unsigned int IDPushPause;

        void pushCloseWindow(const sf::Event e);
        void pushPause(const sf::Event e);

    public:
        Stage(Managers::GraphicManager* gm, Managers::TilesManager* tm, Entities::Characters::Player* p1 = nullptr);

        ~Stage();

        int execute() override;

        virtual void initialize(bool twoPlayers) = 0;

    };
}

#endif //ZOMBIEWITHCLASSES_STAGE_H
