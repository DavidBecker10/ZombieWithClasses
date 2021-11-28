#include "Lava.h"

Lava::Lava() : Obstacle(Ids::lava, "../assets/Tiles/Platformer/Lava.png", { 32.0f, 32.0f }) {

}

Lava::~Lava()
{
}

void Lava::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    switch (idOther) {
    case Ids::Player:
        //EL->remove(player1);
        break;
    case Ids::Player2:
        //EL->remove(player2);
        break;
    default:
        break;
    }
}