#include "Homer.h"
#include "EntityList.h"

Entities::Characters::Homer::Homer(Vector2F pos, Vector2F vel) :
    Enemy(pos, vel, Ids::Ids::Homer, HOMER_PATH) 
{
}

Entities::Characters::Homer::Homer(nlohmann::json j) :
    Enemy({ j["position"] }, { j["vel"] }, Ids::Ids::Homer, HOMER_PATH)
{

}
Entities::Characters::Homer::~Homer() {

}

void Entities::Characters::Homer::update(float t) {
    if (vel.x < 0)
        scale.x = -1;
    else
        scale.x = 1;

    if (position.x < 1555.f)
        position.x += vel.x * t;
    else {
        vel.x *= -1;
    }
    if (position.x > 76)
        position.x += vel.x * t;
    else {
        vel.x *= -1;
    }
    if (!isGround)
        position.y += vel.y * t + GRAVITY;
}

void Entities::Characters::Homer::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    if (idOther != Ids::ground2)
        isGround = false;

    switch (idOther) {
    case Ids::lava:
        vel.x *= -1;
        break;
    case Ids::ground2:
        isGround = true;
        break;
    case Ids::empty:
        isGround = true;
        vel.x *= -1;
        break;
    case Ids::wallL:
        isGround = true;
        vel.x *= -1;
        break;
    case Ids::wallR:
        isGround = true;
        scale.x = -1;
        break;
    case Ids::Projectile:
        isActive = false;
        break;
    case Ids::Ghoul:
        isGround = true;
        break;
    default:
        break;
    }
}


