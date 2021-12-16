#include "Nemesis.h"
#include "stdafx.h"

Entities::Characters::Nemesis::Nemesis(Vector2F pos, Entities::Characters::Player* p1, PlayerTwo* p2) :
    Enemy(pos, Ids::Ids::Nemesis, NEMESIS_PATH, 6, p1, p2), attackFrame(0), bone() {
    frame = 0;
}

Entities::Characters::Nemesis::Nemesis(Vector2F pos, int lf, Player* p1, PlayerTwo* p2) :
    Enemy(pos, Ids::Ids::Nemesis, NEMESIS_PATH, lf, p1, p2), attackFrame(0), bone() {
    frame = 0;
}

Entities::Characters::Nemesis::~Nemesis() {
    bone = nullptr;
}

void Entities::Characters::Nemesis::createProjectile(Vector2F pos) {
    float v, px;
    bool dir;

    scale.x == 1 ? dir = false : dir = true;

    scale.x == 1 ? v = -800.0f : v = 800.0f;

    scale.x == 1 ? px = -35.0f : px = 35.0f;

    bone = new Bone(Vector2F(pos.x + px, pos.y + 30.0f), Vector2F(v, 0.0f), dir);

    EL->insert(bone);
}

void Entities::Characters::Nemesis::update(float t) {
    frame += t;
    attackFrame += t;
    if (!isGround)
        position.y += vel.y * t + GRAVITY;
    if (attackFrame > 2 && (distancePlayer() < 800.0f)) {
        createProjectile(position);

        attackFrame = 0;
    }
}
