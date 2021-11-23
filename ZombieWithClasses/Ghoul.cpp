#include "Ghoul.h"
#include "stdafx.h"

Entities::Characters::Ghoul::Ghoul(Vector2F pos, Vector2F vel, const char* tPath):
	Enemy(pos, vel, tPath)
{
}

Entities::Characters::Ghoul::~Ghoul()
{
}

void Entities::Characters::Ghoul::update(float t)
{
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
    if (!isGround)
        position.y += vel.y * t + GRAVITY;
}

void Entities::Characters::Ghoul::collide(Ids::Ids idOther, Vector2F positionOther, Vector2U dimensionsOther)
{
    if (idOther != Ids::ground2)
        isGround = false;

    switch (idOther) {
    case Ids::lava:
        vel.y *= -1;
        break;
    case Ids::ground2:
        isGround = true;
        vel.y = -900;
        //std::cout << "oi" << std::endl;
        break;
    case Ids::empty:
        isGround = true;
        std::cout << "oi" << std::endl;
        vel.x *= -1;
        break;
    case Ids::wallL:
        isGround = true;
        vel.x *= -1;
        scale.x = 1;
        break;
    case Ids::wallR:
        isGround = true;
        vel.x *= -1;
        scale.x = -1;
        break;
    case Ids::Projectile:
        EL->remove(this);
        break;
    case Ids::Player:
        break;
    default:
        break;
    }
}
