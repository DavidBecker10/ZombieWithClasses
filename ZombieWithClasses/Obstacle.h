#ifndef ZOMBIEWITHCLASSES_OBSTACLE_H
#define ZOMBIEWITHCLASSES_OBSTACLE_H

#include "Tile.h"
#include "Player.h"
class Obstacle :public Entities::Tile {
public:
    Obstacle(const Ids::Ids i = Ids::Ids::empty, const char* p = nullptr, Vector2F s = { 32.0f, 32.0f });
    virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
};


#endif //ZOMBIEWITHCLASSES_OBSTACLE_H
