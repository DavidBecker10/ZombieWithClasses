#include "Nemesis.h"
#include "stdafx.h"
#include "EntityList.h"

Entities::Characters::Nemesis::Nemesis(Vector2F pos, Entities::Characters::Player* p1) :
    Enemy(pos, Ids::Ids::Nemesis, NEMESIS_PATH, 5, p1), attackFrame(0) {
    frame = 0;
}

Entities::Characters::Nemesis::Nemesis(Vector2F pos, int lf, Player* p1) :
    Enemy(pos, Ids::Ids::Nemesis, NEMESIS_PATH, lf, p1), attackFrame(0) {
    frame = 0;
}

Entities::Characters::Nemesis::~Nemesis() {
    bone = nullptr;
}

void Entities::Characters::Nemesis::createProjectile(Vector2F pos) {
    float v, px;
    bool dir;

    scale.x == 1 ? dir = true : dir = false;

    scale.x == 1 ? v = 800.0f : v = -800.0f;

    scale.x == 1 ? px = 35.0f : px = -35.0f;

    bone = new Bone(Vector2F(pos.x + px, pos.y + 30.0f), Vector2F(v, 0.0f), dir);

    EL->insert(bone);
}

void Entities::Characters::Nemesis::update(float t) {
    frame += t;
    attackFrame += t;
    //std::cout << life << std::endl;
//    if(life<1){
//        EL->remove(this);
//    }
//    if (player1->getPosition().x > position.x)
//        scale.x = -1;
//    else
//        scale.x = 1;
    if (!isGround)
        position.y += vel.y * t + GRAVITY;
    if (attackFrame > 2 && (distancePlayer() < 800.0f)) {
        //std::cout << c.getTime() << std::endl;
        createProjectile(position);
        attackFrame = 0;
    }
}
/*
void Entities::Characters::Nemesis::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    if (idOther != Ids::ground2)
        isGround = false;

    switch (idOther) {
    case Ids::lava:
        vel.x *= -1;
        break;
    case Ids::ground2:
        isGround = true;
        break;
    case Ids::air:
        isGround = false;
        break;
    case Ids::wallL:
        isGround = true;
        vel.x *= -1;
        scale.x = 1;
        break;
    case Ids::wallR:
        isGround = true;
        vel.x *= -1;
        scale.x = -1;
        break;
    case Ids::Bone:
        isGround = true;
        break;
    case Ids::Bullet:
        if (frame > 0.4) {
            life--;
            frame = 0;
        }
        isGround = true;
        break;
    case Ids::Player:
        break;
    default:
        break;
    }
}*/
