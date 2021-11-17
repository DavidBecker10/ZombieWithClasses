#include "Collide.h"

Collide::Collide(Vector2F position, Vector2F vel, Ids::Ids ID, const char* pathTexture)
    : Entity(position, vel, ID, pathTexture)
{
}

Collide::~Collide()
{
}
