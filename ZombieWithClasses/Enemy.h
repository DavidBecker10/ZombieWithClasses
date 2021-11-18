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
            Enemy(Vector2F pos, Vector2F vel, Ids::Ids ID, const char* tPath = NULL);
            Enemy();
            ~Enemy();
            virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM);
            void update(float t);
            void draw(Managers::GraphicManager* GM);
            void collide(Ids::Ids idOutro, Vector2F posicaoOutro, Vector2F dimensoesOutro);
        };
    }
}
