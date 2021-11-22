#pragma once
#include "State.h"
#include "Player.h"
#include "CollisionManager.h"

namespace States{
	class Stage :
		public State
	{
    private:
        Managers::GraphicManager* GM;
        Entities::Characters::Player* player1;

        Managers::EventManager EM;
        CollisionManager CM;
        TilesManager TM;
        sf::Clock clock;
        Lists::EntityList EL;

        bool end;
        unsigned int IDCloseScreen;

        void pushCloseWindow(const sf::Event e);

    public:
        Stage(Managers::GraphicManager* gm, Entities::Characters::Player* p1);

        ~Stage();

        int execute() override;

        /*void exit(){ }
        void refresh(float t, Managers::EventManager *EM) { }
        virtual void draw(Managers::GraphicManager *GM) { }

        int returnID() const;*/
	};
}