#include "Lava.h"

namespace Tiles {
    Lava::Lava() : Obstacle(Ids::lava, "../assets/Tiles/Platformer/LavaMine.png") {

    }

    Lava::~Lava() {
    }

    void Lava::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
        switch (idOther) {
        case Ids::Player:
            break;
        case Ids::Player2:
            break;
        default:
            break;
        }
    }
}