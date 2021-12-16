#include "Fire.h"

namespace Tiles {
    Fire::Fire() : Obstacle(Ids::Ids::fire, "../assets/Tiles/Platformer/Fire.png") {

    }

    Fire::~Fire() {

    }

    void Fire::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
        Tile::collide(idOther, positionOther, dimensionsOther);
    }
}