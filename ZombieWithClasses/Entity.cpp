#include "Entity.h"

Entities::Entity::Entity(Vector2F pos, Vector2F v):
position(pos.x, pos.y),
vel(v.x, v.y)
{
}

Entities::Entity::Entity()
{
}

Entities::Entity::~Entity()
{
}
