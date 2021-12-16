#include "stdafx.h"
#include "Rock.h"

Entities::Rock::Rock(Vector2F pos, Vector2F v, bool dir) :
    Projectile(pos, v, Ids::Ids::Rock, ROCK_PATH, dir) {

}

Entities::Rock::~Rock() {

}

void Entities::Rock::update(float t) {
    frame += t;
    position.x += vel.x * t;
    position.y += (vel.y * t + GRAVITY) / 10;
    if (frame > 0.5) {
        energy--;
        frame = 0;
    }
}

void Entities::Rock::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    if (idOther != Ids::empty && idOther != Ids::Homer && idOther != Ids::Ghoul && idOther != Ids::Nemesis)
        energy--;
}