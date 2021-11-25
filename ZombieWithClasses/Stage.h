//
// Created by Gabriel on 18/11/2021.
//

#ifndef ZOMBIEWITHCLASSES_STAGE_H
#define ZOMBIEWITHCLASSES_STAGE_H

#include "State.h"
#include "Player.h"
#include "CollisionManager.h"
#include "Save.h"
#include "Clock.h"

namespace States {
    class Stage :public State, public Save {
    protected:
        Managers::GraphicManager* GM;
        Entities::Characters::Player* player1;

        Managers::EventManager EM;
        Managers::CollisionManager CM;
        Managers::TilesManager* TM;
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
        Stage(Managers::GraphicManager* gm, Managers::TilesManager* tm, Entities::Characters::Player* p1 = nullptr);

        ~Stage();

        int execute() override;

        virtual void initialize() = 0;
        /*void exit(){ }
        void refresh(float t, Managers::EventManager *EM) { }
        virtual void draw(Managers::GraphicManager *GM) { }

        int returnID() const;*/
    };
}

#endif //ZOMBIEWITHCLASSES_STAGE_H
