#include "Bullet.h"

#include "stdafx.h"

#include "Projectile.h"

Entities::Bullet::Bullet(Vector2F pos, Vector2F v, bool dir, int dmg) :
    Projectile(pos, v, Ids::Ids::Bullet, BULLET_PATH, dmg) {
    dir == true ? scale = Vector2F(1, 1) : scale = Vector2F(-1, 1);
    life = 1;
    frame = 0;
}
Entities::Bullet::Bullet(nlohmann::json j, bool dir) :
    Projectile({ j["position"] }, { j["vel"] }, Ids::Ids::Bullet, BULLET_PATH) {
    dir == true ? scale = Vector2F(1, 1) : scale = Vector2F(-1, 1);
    life = 1;
    frame = 0;
}

Entities::Bullet::~Bullet() {
}

/*void Entities::Bullet::update(float t) {
    position.x += vel.x * t;
}

void Entities::Bullet::draw() {
    GM->loadTexture(textPath);
    dimensions = GM->getSize(textPath);
    GM->draw(textPath, position, scale);
}

void Entities::Projectile::initialize(Managers::GraphicManager *GM, Managers::EventManager *EM,
                                      Managers::CollisionManager *CM) {
    GM->loadTexture(textPath);
    dimensions = GM->getSize(textPath);
}*/

void Entities::Bullet::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    switch (idOther) {
    case Ids::Enemy:
        break;
    case Ids::Nemesis:
        life--;
        break;
    case Ids::Homer:
        life--;
        break;
    case Ids::Ghoul:
        life--;
        break;
    case Ids::ground10:
        life--;
        break;
    case Ids::wallL:
        life--;
        break;
    case Ids::wallR:
        life--;
        break;
    default:
        break;
    }
}

//void Entities::Bullet::update(float t) {
//    frame += t;
//    position.x += vel.x * t;
//    if(frame>0.8){
//        life--;
//        frame = 0;
//    }
//}


