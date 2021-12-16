#include "Platform.h"

namespace Tiles {
    Platform::Platform() : Obstacle(Ids::Ids::platform, "../assets/Tiles/Platformer/Ground_11.png") {

    }

    Platform::~Platform() {

    }

    void Platform::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
        Tile::collide(idOther, positionOther, dimensionsOther);
    }
}