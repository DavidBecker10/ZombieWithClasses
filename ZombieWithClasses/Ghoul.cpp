#include "Ghoul.h"
#include "stdafx.h"

Entities::Characters::Ghoul::Ghoul(Vector2F pos, Player* p1) :
    Enemy(pos, Ids::Ids::Ghoul, GHOUL_PATH, 2, p1) {
    //jumpTime = 0;
    //isJumping = false;
    faceLeft = true;
}

Entities::Characters::Ghoul::Ghoul(Vector2F pos, int lf, Player* p1) :
    Enemy(pos, Ids::Ids::Ghoul, GHOUL_PATH, lf, p1)
{
    faceLeft = true;
    //jumpTime = 0;
    //isJumping = false;
}

Entities::Characters::Ghoul::~Ghoul() {

}

void Entities::Characters::Ghoul::update(float t) {
    frame += t;
    if (distancePlayer() < 600.0f) {
        if (faceLeft)
            position.x += -100 * t;
        else
            position.x += 100 * t;
    }
    if (!isGround)
        position.y += vel.y * t + GRAVITY;
}


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

//void Entities::Characters::Ghoul::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
//    if (idOther != Ids::ground2)
//        isGround = false;
//
//    switch (idOther) {
//        case Ids::lava:
//            isJumping = false;
//            vel.x *= -1;
//            break;
//        case Ids::ground2:
//            isJumping = false;
//            isGround = true;
//            break;
//        case Ids::air:
//            isJumping = true;
//            isGround = false;
//            break;
//        case Ids::wallL:
//            isJumping = false;
//            isGround = true;
//            vel.x *= -1;
//            scale.x = -1;
//            break;
//        case Ids::wallR:
//            isJumping = false;
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
