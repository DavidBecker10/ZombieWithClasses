#pragma once
#include "Entity.h"

namespace Entities
{
    namespace Characters
    {
        class Player;
    }

    namespace Obstacles
    {
        class Obstacle :
            public Entity
        {
        public:
            Obstacle();
            ~Obstacle();
            virtual void update(float t);
            void initialize(Managers::EventManager* EM, Managers::CollisionManager* CM);
            void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
            virtual void collidePlayer(Entities::Characters::Player* pP) = 0;
        };
    }
}