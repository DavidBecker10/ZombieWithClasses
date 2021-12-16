#include "Bullet.h"

#include "stdafx.h"

#include "Projectile.h"

Entities::Bullet::Bullet(Vector2F pos, Vector2F v, bool dir) :
    Projectile(pos, v, Ids::Ids::Bullet, BULLET_PATH, dir) {
}

Entities::Bullet::~Bullet() {
}

void Entities::Bullet::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    if (idOther == Ids::Homer || idOther == Ids::Ghoul || idOther == Ids::Nemesis || idOther == Ids::Bone) {
        energy--;
    }
}