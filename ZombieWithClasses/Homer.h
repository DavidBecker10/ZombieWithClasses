#pragma once
#include "Enemy.h"

namespace Entities
{
    namespace Characters
    {
        class Homer :
            public Enemy
        {
        private:

        public:
            Homer(sf::Vector2f pos, sf::Vector2f vel, Ids::Ids ID, const char* tPath = "../Sprites/Zombies/ZombieMan/animation/Attack1.png");
            ~Homer();
            void update(float t);
            void collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther);
        };
    }
}