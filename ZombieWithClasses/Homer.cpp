#include "Homer.h"

Entities::Characters::Homer::Homer(Vector2F pos, Player* p1, PlayerTwo* p2) :
    Enemy(pos, Ids::Ids::Homer, HOMER_PATH, 2, p1, p2) {
    faceLeft = true;
}

Entities::Characters::Homer::Homer(Vector2F pos, int lf, Player* p1, PlayerTwo* p2) :
    Enemy(pos, Ids::Ids::Homer, HOMER_PATH, lf, p1, p2)
{
    faceLeft = true;
}
Entities::Characters::Homer::~Homer() {

}

void Entities::Characters::Homer::update(float t) {
    frame += t;
    if (distancePlayer() < 400.0f) {
        if (faceLeft)
            position.x += -80 * t;
        else
            position.x += 80 * t;
    }
    if (!isGround)
        position.y += vel.y * t + GRAVITY;
}
