#include "Enemy.h"
#include "stdafx.h"
#include "CollisionManager.h"

Entities::Characters::Enemy::Enemy(Vector2F pos, Ids::Ids id, const char* tPath, int lf, Player* p1) :
    //Character(pos, vel, Ids::Ids::Enemy, "../assets/Zombies/ZombieMan/animation/Walk1test.png")
    Character(pos, id, tPath, lf), player1(p1)
{
    frame = 1;
    faceLeft = true;
}

Entities::Characters::Enemy::~Enemy()
{
    player1 = NULL;
}

void Entities::Characters::Enemy::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM)
{
    isGround = false;
    GM->loadTexture(textPath);
    dimensions = GM->getSize(textPath);
    //CM->addCollide(this);
}

//void Entities::Characters::Enemy::update(float t)
//{
//    if (position.x < 1555.f)
//        position.x += vel.x * t;
//    else {
//        vel.x *= -1;
//    }
//    if(position.x > 76)
//        position.x += vel.x * t;
//    else {
//        vel.x *= -1;
//    }
//    if(position.y < 1444.f)
//	    position.y += vel.y * t + GRAVITY;
//}

void Entities::Characters::Enemy::draw()
{
    //GM->draw(textPath, position, { 1, 9 }, { 0, 5 });
    GM->draw(textPath, position, scale);
}

void Entities::Characters::Enemy::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther)
{
    if (idOther != Ids::ground2)
        isGround = false;
    //    if (idOther == Ids::Ids::Ghoul || idOther == Ids::Ids::Homer) {
    //        Vector2F distance = position - positionOther;
    //        Vector2F ajust = (0.5f, 0.5f);
    //        position += distance * ajust;
    //
    //        //std::cout << "Enemy to enemy collision" << std::endl;
    //        vel.x *= -1;
    //        //vel.y *= -1;
    //        isGround = true;
    //    }
    switch (idOther) {
    case Ids::lava:
        vel.x = 0;
        isGround = true;
        //position = -200;
        break;
    case Ids::ground2:
        isGround = true;
        break;
    case Ids::empty:
        isGround = true;
        vel.x *= -1;
        break;
    case Ids::wallL:
        isGround = true;
        vel.x *= -1;
        break;
    case Ids::wallR:
        isGround = true;
        vel.x *= -1;
        break;
    case Ids::Bullet:
        if (frame > 0.4) {
            life--;
            frame = 0;
        }
        if (life <= 0) {
            player1->incrementScore(10);
        }
        isGround = true;
        break;
    case Ids::Bone:
        isGround = true;
        break;
    case Ids::Homer:
        isGround = true;
        break;
    case Ids::Ghoul:
        isGround = true;
        break;
    case Ids::Nemesis:
        isGround = true;
        break;
    case Ids::Player:
        isGround = true;
        break;
    case Ids::Player2:
        isGround = true;
        break;
    case Ids::spiderweb:
        isGround = true;
        break;
    default:
        break;
    }
}

nlohmann::json Entities::Characters::Enemy::convertJSON() {
    return {
            { "ID", ID},
            {"position", position.convertJSON()},
            //{"vel", vel.convertJSON()},
           // {"textPath", textPath},
            {"life", life},
            {"Stage", currentStage}
    };
}

float Entities::Characters::Enemy::distancePlayer() {
    if (position.x > player1->getPosition().x) {
        scale.x = -1;
        faceLeft = true;
        return position.x - player1->getPosition().x;
    }
    else {
        scale.x = 1;
        faceLeft = false;
        return player1->getPosition().x - position.x;
    }
}
