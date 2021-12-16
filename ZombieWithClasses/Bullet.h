#ifndef ZOMBIEWITHCLASSES_BULLET_H
#define ZOMBIEWITHCLASSES_BULLET_H

#include "Projectile.h"

namespace Entities {
    class Bullet : public Projectile {
    public:
        Bullet(Vector2F pos = { 0.0f, 0.0f }, Vector2F v = { 0.0f, 0.0f }, bool dir = true);
        ~Bullet();
        void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
    };
}

#endif //ZOMBIEWITHCLASSES_BULLET_H
