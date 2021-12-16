#include "Projectile.h"

Entities::Projectile::Projectile(Vector2F pos, Vector2F v, Ids::Ids i, const char* tP, bool dir) :
    Entity(pos, v, i, tP) {
    energy = 1;
    frame = 0;
    dir == true ? scale = Vector2F(1, 1) : scale = Vector2F(-1, 1);
}


Entities::Projectile::~Projectile() {
}

void Entities::Projectile::update(float t) {
    frame += t;
    position.x += vel.x * t;
    if (frame > 1) {
        energy--;
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
}

nlohmann::json Entities::Projectile::convertJSON() {
    return {
            {"ID", ID},
            {"position", position.convertJSON()},
            {"vel", vel.convertJSON()},
            {"dir", dir}
    };
}
