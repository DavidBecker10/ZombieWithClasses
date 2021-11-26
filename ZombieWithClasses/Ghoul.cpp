#include "Ghoul.h"
#include "EntityList.h"
#include "stdafx.h"

Entities::Characters::Ghoul::Ghoul(Vector2F pos, Vector2F vel) :
    Enemy(pos, vel, Ids::Ids::Ghoul, GHOUL_PATH)
{
    isGround = false;
}
Entities::Characters::Ghoul::Ghoul(nlohmann::json j) :
    Enemy({ j["position"] }, { j["vel"] }, Ids::Ids::Ghoul, GHOUL_PATH)
{

}
Entities::Characters::Ghoul::~Ghoul() {

}

void Entities::Characters::Ghoul::update(float t) {
    if (position.x < 1555.f)
        position.x += vel.x * t;
    else {
        vel.x *= -1;
        scale.x = -1;
    }
    if (position.x > 76)
        position.x += vel.x * t;
    else {
        vel.x *= -1;
        scale.x = 1;
    }
    if (!isGround || c.getElapsedTime().asSeconds() > 3.0)
        position.y += vel.y * t + GRAVITY;
}

void Entities::Characters::Ghoul::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    if (idOther != Ids::ground2) {
        vel.y += 900;
        isGround = false;
    }

    switch (idOther) {
    case Ids::lava:
        vel.x *= -1;
        break;
    case Ids::ground2:
        vel.y = -900;
        isGround = true;
        c.restart();
        break;
    case Ids::empty:
        isGround = true;
        vel.x *= -1;
        scale.x = 1;
        break;
    case Ids::wallL:
        isGround = true;
        vel.x *= -1;
        scale.x = -1;
        break;
    case Ids::wallR:
        isGround = true;
        vel.x *= -1;
        scale.x = -1;
        break;
    case Ids::Projectile:
        EL->remove(this);
        break;
    case Ids::Homer:
        isGround = true;
        break;
    default:
        break;
    }
}