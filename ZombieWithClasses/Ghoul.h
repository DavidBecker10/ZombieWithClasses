#pragma once
#include "Enemy.h"

namespace Entities
{
    namespace Characters
    {
        class Ghoul :
            public Enemy
        {
        private:

        public:
            Ghoul(sf::Vector2f pos, sf::Vector2f vel, Ids::Ids ID, const char* tPath = "../Sprites/Zombies/ZombieWoman/animation/Attack1.png");
            ~Ghoul();
            void update(float t);
            void collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther);
        };
    }
}
