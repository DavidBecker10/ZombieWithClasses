#include "stdafx.h"
#include "Bone.h"

Entities::Bone::Bone(Vector2F pos, Vector2F v, bool dir, int dmg) :
    Projectile(pos, v, Ids::Ids::Bone, BONE_PATH, dmg) {
    dir == true ? scale = Vector2F(1, 1) : scale = Vector2F(-1, 1);

}

Entities::Bone::Bone(nlohmann::json j, bool dir) :
    Projectile({ j["position"] }, { j["vel"] }, Ids::Ids::Bone, BONE_PATH) {
    dir == true ? scale = Vector2F(1, 1) : scale = Vector2F(-1, 1);

}

Entities::Bone::~Bone() {

}

void Entities::Bone::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    switch (idOther) {
    case Ids::Player:
        life--;
        break;
    default:
        break;
    }
}


