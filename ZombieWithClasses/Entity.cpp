#include "Entity.h"
#include "EntityList.h"
#include "CollisionManager.h"
#include "json.hpp"
Entities::Entity::Entity(Vector2F pos, Vector2F v, Ids::Ids ID, const char* tP) :
    Ent(ID, tP),
    vel{ v },
    position(pos),
    scale(Vector2F(1.f, 1.f)),
    isActive(true)
{
}

Entities::Entity::~Entity()
{
}

void Entities::Entity::draw()
{
    GM->draw(textPath, position);
}

nlohmann::json Entities::Entity::convertJSON() {
    return {
            {"ID", ID},
            {"position", position.convertJSON()},
            {"vel", vel.convertJSON()},
            {"textPath", textPath},
            {"dimensions", dimensions.convertJSON()}
    };
}

Lists::EntityList* Entities::Entity::EL = NULL;
int Entities::Entity::currentStage = -1;