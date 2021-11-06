#include "Entity.h"

Entities::Entity::Entity(sf::Vector2f pos, sf::Vector2f v):
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
//a