#include "stdafx.h"
#include "Bone.h"

Entities::Bone::Bone(Vector2F pos, Vector2F v, bool dir) :
    Projectile(pos, v, Ids::Ids::Bone, BONE_PATH, dir) {

}

Entities::Bone::~Bone() {

}

void Entities::Bone::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    if (idOther != Ids::empty && idOther != Ids::Homer && idOther != Ids::Ghoul && idOther != Ids::Nemesis && idOther != Ids::Bullet)
        energy--;
}