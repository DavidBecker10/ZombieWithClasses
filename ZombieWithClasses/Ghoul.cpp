#include "Ghoul.h"
#include "stdafx.h"
Entities::Characters::Ghoul::Ghoul(Vector2F pos, Player* p1, PlayerTwo* p2) :
    Enemy(pos, Ids::Ids::Ghoul, GHOUL_PATH, 2, p1, p2), attackCooldown(0), rock() {
    faceLeft = true;

}
Entities::Characters::Ghoul::Ghoul(Vector2F pos, int lf, Player* p1, PlayerTwo* p2) :
    Enemy(pos, Ids::Ids::Ghoul, GHOUL_PATH, lf, p1, p2), attackCooldown(0), rock()
{
    faceLeft = true;
}
Entities::Characters::Ghoul::~Ghoul() {
    rock = nullptr;
}

void Entities::Characters::Ghoul::update(float t) {
    frame += t;
    attackCooldown += t;
    if (distancePlayer() < 600.0f) {
        if (faceLeft)
            position.x += -100 * t;
        else
            position.x += 100 * t;
        if (attackCooldown > 3) {
            createProjectile(position);
            attackCooldown = 0;
        }
    }
    if (!isGround)
        position.y += vel.y * t + GRAVITY;
}

void Entities::Characters::Ghoul::createProjectile(Vector2F pos) {
    float v, px;
    bool dir;

    scale.x == 1 ? dir = false : dir = true;

    scale.x == 1 ? v = -700.0f : v = 700.0f;

    scale.x == 1 ? px = -35.0f : px = 35.0f;

    rock = new Rock(Vector2F(pos.x + px, pos.y - 10), Vector2F(v, 0.0f), dir);

    EL->insert(rock);
}
