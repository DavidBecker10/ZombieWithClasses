#ifndef ZOMBIEWITHCLASSES_STAGE_H
#define ZOMBIEWITHCLASSES_STAGE_H

#include "State.h"
#include "PlayerOne.h"
#include "PlayerTwo.h"
#include "CollisionManager.h"
#include "ScreenManager.h"
#include "Save.h"
#include "Clock.h"

namespace States {
    class Stage :public State, public Save {
    protected:
        Entities::Characters::PlayerOne* player1;
        Entities::Characters::PlayerTwo* player2;

        Managers::GraphicManager* GM;
        Managers::EventManager EM;
        Managers::CollisionManager CM;
        Managers::TilesManager* TM;
        Managers::ScreenManager* SM;
        //sf::Clock clock;
        Clock clock;
        Lists::EntityList EL;

        void setReturnCode(int rc) { returnCode = rc; }
        int returnCode;

    private:

        unsigned int IDCloseScreen;
        unsigned int IDPushPause;

        void pushCloseWindow(const sf::Event e);
        void pushPause(const sf::Event e);

    public:
        Stage(Managers::GraphicManager* gm, Managers::TilesManager* tm, Managers::ScreenManager* sm, Entities::Characters::PlayerOne* p1 = nullptr);

        ~Stage();

        int execute() override;

        virtual void initialize(bool numPlayers) = 0;
        /*void exit(){ }
        void refresh(float t, Managers::EventManager *EM) { }
        virtual void draw(Managers::GraphicManager *GM) { }

        int returnID() const;*/
    };
}

#endif //ZOMBIEWITHCLASSES_STAGE_H
