#ifndef ZOMBIEWITHCLASSES_LAVA_H
#define ZOMBIEWITHCLASSES_LAVA_H

#include "Obstacle.h"
#include "PlayerTwo.h"
namespace Tiles {
    class Lava : public Obstacle {
    public:
        Lava();

        ~Lava();

        void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
    };
}

#endif //ZOMBIEWITHCLASSES_LAVA_H
