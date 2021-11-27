#ifndef ZOMBIEWITHCLASSES_ENEMY_H
#define ZOMBIEWITHCLASSES_ENEMY_H
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
            Enemy(Vector2F pos = { 0.0f, 0.0f }, Vector2F vel = { 0.0f, 0.0f }, Ids::Ids id = Ids::Ids::empty, const char* tPath = nullptr);
            ~Enemy();
            virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);
            virtual void update(float t) = 0;
            void draw();
            void collide(Ids::Ids idOutro, Vector2F posicaoOutro, Vector2F dimensoesOutro);
        };
    }
}

#endif //ZOMBIEWITHCLASSES_ENEMY_H