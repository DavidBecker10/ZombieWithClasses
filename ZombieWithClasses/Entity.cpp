#include "Entity.h"
#include "EntityList.h"
#include "CollisionManager.h"

Entities::Entity::Entity(Vector2F pos, Vector2F v, Ids::Ids ID, const char* tP) :
    Ent(ID, tP),
    vel{ v },
    position(pos),
    scale(Vector2F(1.f, 1.f))
{
}

Entities::Entity::~Entity()
{
}

void Entities::Entity::draw()
{
    GM->draw(textPath, position);
}

/*void Entities::Entity::update(float t) {
    position += (vel*t);
}*/

Lists::EntityList* Entities::Entity::EL = NULL;