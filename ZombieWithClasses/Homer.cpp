#include "Homer.h"
#include "stdafx.h"

Entities::Characters::Homer::Homer(sf::Vector2f pos, sf::Vector2f vel, Ids::Ids ID, const char* tPath):
	Enemy(pos, vel, ID, tPath)
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

void Entities::Characters::Homer::collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther)
{
    std::string imprimir;

    if (idOther != Ids::ground2)
        isGround = false;

    switch (idOther) {
    case Ids::lava:
        vel.y *= -1;
        break;
    case Ids::ground2:
        isGround = true;
        break;
    case Ids::air:
        isGround = false;
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
        //EList->remove(this);
        break;
    case Ids::Player:
        break;
    default:
        break;
    }
}
