#include "Projectile.h"

Entities::Projectile::Projectile(Vector2F pos, Vector2F v, Ids::Ids i, const char* tP, int dmg) :
    Entity(pos, v, i, tP), damage(dmg) {
    life = 1;
    frame = 0;
}


Entities::Projectile::~Projectile() {
}

void Entities::Projectile::update(float t) {
    frame += t;
    position.x += vel.x * t;
    if (frame > 0.8) {
        life--;
        frame = 0;
    }
}

void Entities::Projectile::draw() {
    GM->loadTexture(textPath);
    dimensions = GM->getSize(textPath);
    GM->draw(textPath, position, scale);
}

void Entities::Projectile::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM,
    Managers::CollisionManager* CM) {
    GM->loadTexture(textPath);
    dimensions = GM->getSize(textPath);
}

void Entities::Projectile::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    switch (idOther) {
    case Ids::Enemy:
        break;
    default:
        break;
    }
}

nlohmann::json Entities::Projectile::convertJSON() {
    return {
            {"ID", ID},
            {"position", position.convertJSON()},
            {"vel", vel.convertJSON()},
            // {"textPath", textPath},
    };
}
