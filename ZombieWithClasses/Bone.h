#ifndef ZOMBIEWITHCLASSES_BONE_H
#define ZOMBIEWITHCLASSES_BONE_H

#include "Projectile.h"

namespace Entities {
    class Bone : public Projectile {
    public:
        Bone(Vector2F pos = { 0.0f, 0.0f }, Vector2F v = { 0.0f, 0.0f }, bool dir = false);

        ~Bone();

        void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
    };
}

#endif //ZOMBIEWITHCLASSES_BONE_H
