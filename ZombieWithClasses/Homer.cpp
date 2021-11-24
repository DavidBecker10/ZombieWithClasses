#include "Homer.h"
#include "stdafx.h"

Entities::Characters::Homer::Homer(Vector2F pos, Vector2F vel, const char* tPath):
	Enemy(pos, vel, tPath)
{
}

Entities::Characters::Homer::~Homer()
{

}

void Entities::Characters::Homer::update(float t)
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

void Entities::Characters::Homer::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther)
{
    /*if (idOther != Ids::ground2)
        isGround = false;*/

    switch (idOther) {
    case Ids::lava:
        std::cout << "lava" << std::endl;
        vel.x *= -1;
        break;
    case Ids::ground2:
        isGround = true;
        //std::cout << "chao" << std::endl;
        break;
    case Ids::empty:
        scale.x = -1;
        isGround = true;
        //std::cout << "empty" << std::endl;
        vel.x *= -1;
        break;
    case Ids::wallL:
        isGround = true;
        vel.x *= -1;
        scale.x = -1;
        break;
    /*case Ids::wallR:
        isGround = true;
        vel.x *= -1;
        scale.x = -1;
        break;*/
    case Ids::Projectile:
        std::cout << "Falici" << std::endl;
        EL->remove(this);
        break;
    case Ids::Player:
        break;
    default:
        break;
    }
}