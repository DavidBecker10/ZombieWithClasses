#ifndef ZOMBIEWITHCLASSES_STAGE_H
#define ZOMBIEWITHCLASSES_STAGE_H

#include "State.h"
#include "PlayerTwo.h"
#include "PlayerOne.h"
#include "CollisionManager.h"

namespace States {
    class Stage :public State {
    private:
        Managers::GraphicManager* GM;
        Entities::Characters::PlayerOne* player1;
        Entities::Characters::PlayerTwo* player2;

        Managers::EventManager EM;
        Managers::CollisionManager CM;
        Managers::TilesManager TM;
        sf::Clock clock;
        Lists::EntityList EL;

        bool end;
        unsigned int IDCloseScreen;

        void pushCloseWindow(const sf::Event e);

    public:
        Stage(Managers::GraphicManager* gm, Entities::Characters::PlayerOne* p1, Entities::Characters::PlayerTwo* p2);

        ~Stage();

        int execute() override;

        /*void exit(){ }
        void refresh(float t, Managers::EventManager *EM) { }
        virtual void draw(Managers::GraphicManager *GM) { }

        int returnID() const;*/
    };
}

#endif //ZOMBIEWITHCLASSES_STAGE_H
