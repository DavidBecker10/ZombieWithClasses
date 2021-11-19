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
            void update(float t);
            void draw(Managers::GraphicManager* GM);
            void collide(Ids::Ids idOutro, sf::Vector2f posicaoOutro, sf::Vector2u dimensoesOutro);
        };
    }
}
