#pragma once
#include "Character.h"

namespace Entities
{
    namespace Characters
    {
        class Enemy :
            public Character
        {
        private:

        public:
            Enemy(sf::Vector2f pos, sf::Vector2f vel, Ids::Ids ID, const char* tPath = NULL);
            Enemy();
            ~Enemy();
            virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM);
            virtual void update(float t) = 0;
            void draw(Managers::GraphicManager* GM);
            void collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther) = 0;
        };
    }
}
