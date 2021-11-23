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
            Enemy(Vector2F pos = { 0.0f, 0.0f }, Vector2F vel = { 0.0f, 0.0f }, const char* tPath = nullptr);
            ~Enemy();
            virtual void initialize(Managers::EventManager* EM, Managers::CollisionManager* CM);
            virtual void update(float t) = 0;
            void draw();
            void collide(Ids::Ids idOutro, Vector2F posicaoOutro, Vector2F dimensoesOutro);
        };
    }
}
