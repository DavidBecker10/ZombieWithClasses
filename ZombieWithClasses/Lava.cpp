#include "Lava.h"

Lava::Lava() : Obstacle(Ids::lava, "../assets/Tiles/Platformer/Lava.png", { 32.0f, 32.0f }) {

}

void Lava::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    switch (idOther) {
    case Ids::Enemy:
        /*...*/
        break;
    case Ids::Player:
        /*...*/
        break;
    default:
        break;
    }
}
