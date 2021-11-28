#include "Entity.h"
#include "CollisionManager.h"
#include "json.hpp"

Entities::Entity::Entity(Vector2F pos, Vector2F v, Ids::Ids ID, const char* tP, int lf) :
    Ent(ID, tP),
    vel{ v },
    position(pos),
    scale(Vector2F(1.f, 1.f)),
    life(lf)
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
            //{"vel", vel.convertJSON()},
            //{"textPath", textPath},
            {"life", life},
            {"Stage", currentStage}
    };
}


/*void Entities::Entity::update(float t) {
    position += (vel*t);
}*/
Lists::EntityList* Entities::Entity::EL = NULL;
int Entities::Entity::currentStage = -1;