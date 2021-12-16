#ifndef ZOMBIEWITHCLASSES_FIRE_H
#define ZOMBIEWITHCLASSES_FIRE_H

#include "Obstacle.h"

namespace Tiles {
    class Fire : public Obstacle {
    public:
        Fire();

        ~Fire();

        void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
    };
}

#endif //ZOMBIEWITHCLASSES_FIRE_H
