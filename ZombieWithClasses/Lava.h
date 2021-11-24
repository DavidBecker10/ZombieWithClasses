#pragma once
#include "Obstacle.h"

namespace Entities
{
    namespace Obstacles
    {
        class Lava :
            public Obstacle
        {
        public:
            Lava();
            ~Lava();
            virtual void update(float t);
            void initialize(Managers::EventManager* EM, Managers::CollisionManager* CM);
            void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
            virtual void collidePlayer(Entities::Characters::Player* pP);
        };
    }
}

