#ifndef ZOMBIEWITHCLASSES_PROJECTILE_H
#define ZOMBIEWITHCLASSES_PROJECTILE_H


#include "Entity.h"

namespace Entities {
    class Projectile : public Entity {
    public:
        Projectile(Vector2F pos = { 0.0f, 0.0f }, Vector2F v = { 0.0f, 0.0f }, const char* tP = nullptr, bool dir = false);
        ~Projectile();

        virtual void update(float t);
        void draw(Managers::GraphicManager* g);
        void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);
        void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
    };
}

#endif //ZOMBIEWITHCLASSES_PROJECTILE_H


