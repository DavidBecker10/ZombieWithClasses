//
// Created by Gabriel on 24/11/2021.
//

#ifndef ZOMBIEWITHCLASSES_LAVA_H
#define ZOMBIEWITHCLASSES_LAVA_H

#include "Obstacle.h"

class Lava : public Obstacle {
public:
    Lava();

    void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
};


#endif //ZOMBIEWITHCLASSES_LAVA_H
