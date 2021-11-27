#ifndef ZOMBIEWITHCLASSES_CHARACTER_H
#define ZOMBIEWITHCLASSES_CHARACTER_H
#include "Entity.h"

namespace Entities
{
    namespace Characters
    {
        class Character :public Entity
        {
        protected:
            bool isGround;

        public:
            Character(Vector2F pos = { 0.0f, 0.0f }, Vector2F v = { 0.0f, 0.0f }, Ids::Ids ID = Ids::Ids::empty, const char* tPath = nullptr);
            ~Character();
            virtual void update(float t);
            virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);
            virtual void draw();
            virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) = 0;
        };
    }
}

#endif //ZOMBIEWITHCLASSES_CHARACTER_H