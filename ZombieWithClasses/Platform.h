#ifndef ZOMBIEWITHCLASSES_PLATFORM_H
#define ZOMBIEWITHCLASSES_PLATFORM_H

#include "Obstacle.h"
namespace Tiles {
    class Platform : public Obstacle {
    public:
        Platform();

        ~Platform();
        void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
    };
}

#endif //ZOMBIEWITHCLASSES_PLATFORM_H
