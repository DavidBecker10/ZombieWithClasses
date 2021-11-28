#include "Homer.h"

Entities::Characters::Homer::Homer(Vector2F pos, Player* p1) :
    Enemy(pos, Ids::Ids::Homer, HOMER_PATH, 2, p1) {
    //frame = 1;
    faceLeft = true;
}

Entities::Characters::Homer::Homer(Vector2F pos, int lf, Player* p1) :
    Enemy(pos, Ids::Ids::Homer, HOMER_PATH, lf, p1)
{
    faceLeft = true;
}

Entities::Characters::Homer::~Homer() {

}

void Entities::Characters::Homer::update(float t) {
    frame += t;
    if (distancePlayer() < 400.0f) {
        if (faceLeft)
            position.x += -80 * t;
        else
            position.x += 80 * t;
    }
    if (!isGround)
        position.y += vel.y * t + GRAVITY;
}
//    frame += t;
//    if (position.x < 1555.f)
//        position.x += vel.x * t;
//    else {
//        vel.x *= -1;
//        scale.x = -1;
//    }
//    if (position.x > 76)
//        position.x += vel.x * t;
//    else {
//        vel.x *= -1;
//        scale.x = 1;
//    }
//    if (!isGround)
//        position.y += vel.y * t + GRAVITY;
//}

//void Entities::Characters::Homer::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
//    if (idOther != Ids::ground2)
//        isGround = false;
//
//    switch (idOther) {
//        case Ids::lava:
//            vel.x *= -1;
//            break;
//        case Ids::ground2:
//            isGround = true;
//            break;
//        case Ids::air:
//            isGround = false;
//            break;
//        case Ids::wallL:
//            isGround = true;
//            vel.x *= -1;
//            scale.x = -1;
//            break;
//        case Ids::wallR:
//            isGround = true;
//            vel.x *= -1;
//            scale.x = -1;
//            break;
//        case Ids::Bullet:
//            if(frame>0.4) {
//                life--;
//                frame = 0;
//            }
//            isGround = true;
//            //EL->remove(this);
//            break;
//        case Ids::Homer:
//            isGround = true;
//            break;
//        case Ids::Ghoul:
//            isGround = true;
//            break;
//        case Ids::Nemesis:
//            isGround = true;
//            break;
//        case Ids::Player:
//            isGround = true;
//            break;
//        default:
//            break;
//    }
//}


