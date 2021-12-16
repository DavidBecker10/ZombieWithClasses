#ifndef ZOMBIEWITHCLASSES_ROCK_H
#define ZOMBIEWITHCLASSES_ROCK_H

#include "Projectile.h"

namespace Entities {
    class Rock : public Projectile {
    public:
        Rock(Vector2F pos = { 0.0f, 0.0f }, Vector2F v = { 0.0f, 0.0f }, bool dir = false);

        ~Rock();

        void update(float t);

        void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
    };
}


#endif //ZOMBIEWITHCLASSES_ROCK_H
