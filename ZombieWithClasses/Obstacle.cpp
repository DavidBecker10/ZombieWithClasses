//
// Created by Gabriel on 24/11/2021.
//

#include "Obstacle.h"


Obstacle::Obstacle(const Ids::Ids i, const char* p, Vector2F s) : Tile(i, p, s) {

}

void Obstacle::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    Tile::collide(idOther, positionOther, dimensionsOther);
}
