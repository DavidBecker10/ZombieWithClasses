#include "Entity.h"
#include "CollisionManager.h"
#include "json.hpp"

Entities::Entity::Entity(Vector2F pos, Vector2F v, Ids::Ids ID, const char* tP, int lf) :
    Ent(ID, tP),
    vel{ v },
    position(pos),
    scale(Vector2F(1.f, 1.f)),
    energy(lf)
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
            {"ID",       ID},
            {"position", position.convertJSON()},
            {"life",     energy},
            {"Stage",    currentStage}
    };
}

int Entities::Entity::currentStage = -1;

void Entities::Entity::adjust() {
    position += adjusts;
    adjusts = Vector2F(0.0f, 0.0f);
}
