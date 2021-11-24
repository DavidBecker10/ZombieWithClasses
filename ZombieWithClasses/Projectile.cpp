#include "Projectile.h"
#include "EntityList.h"

Entities::Projectile::Projectile(Vector2F pos, Vector2F v, const char* tP, bool dir) :
    Entity(pos, v, Ids::Ids::Projectile, tP) {
    dir == true ? scale = Vector2F(1, 1) : scale = Vector2F(-1, 1);
}


Entities::Projectile::~Projectile() {
}

void Entities::Projectile::update(float t) {

    position.x += vel.x * t;
}

void Entities::Projectile::draw() {
    GM->loadTexture(textPath);
    dimensions = GM->getSize(textPath);
    GM->draw(textPath, position, scale);
}

void Entities::Projectile::initialize(Managers::EventManager* EM,
    Managers::CollisionManager* CM) {
    GM->loadTexture(textPath);
    dimensions = GM->getSize(textPath);
}

void Entities::Projectile::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    switch (idOther) {
    case Ids::Enemy:
        //std::cout << EL->getSize() << std::endl;
        //EL->remove(this);
        //std::cout << EL->getSize() << std::endl;
        break;
    default:
        break;
    }
}
