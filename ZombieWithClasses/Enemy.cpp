#include "Enemy.h"
#include "stdafx.h"
#include "CollisionManager.h"

Entities::Characters::Enemy::Enemy(Vector2F pos, Vector2F vel, const char* tPath) :
    //Character(pos, vel, Ids::Ids::Enemy, "../assets/Zombies/ZombieMan/animation/Walk1test.png")
    Character(pos, vel, Ids::Ids::Enemy, tPath)
{
}

Entities::Characters::Enemy::~Enemy()
{
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

void Entities::Characters::Enemy::draw(Managers::GraphicManager* GM)
{
    //GM->draw(textPath, position, { 1, 9 }, { 0, 5 });
    GM->draw(textPath, position, scale);
}

void Entities::Characters::Enemy::collide(Ids::Ids idOutro, Vector2F posicaoOutro, Vector2F dimensoesOutro)
{
    if (idOutro == Ids::Ids::Player) {
        // std::cout << "nhac nhac nham nham heroi gostoso" << std::endl;
    }
    else if (idOutro == Ids::Ids::Enemy) {

        Vector2F distance = position - posicaoOutro;
        Vector2F sergio(0.5f, 0.5f);
        position += distance * sergio;

        std::cout << "Enemy to enemy collision" << std::endl;
        vel.x *= -1;
        vel.y *= -1;
    }

    /**std::string imprimir;


    switch (idOutro) {
    case Ids::Player:
        imprimir = "Colidiu Player";
        std::cout << imprimir << std::endl;
        break;
    case Ids::ground1:
        imprimir = "fui ludibriado";
        std::cout << imprimir << std::endl;
        break;
    case Ids::ground2:
        imprimir = "cai";
        std::cout << imprimir << std::endl;
        break;
    case Ids::empty:
        imprimir = "mano o que ta acontecendo";
        std::cout << imprimir << std::endl;
        break;
    case Ids::ground3:
        imprimir = "pontudo";
        std::cout << imprimir << std::endl;
        break;
    case Ids::ground4:
        imprimir = "estou livre";
        std::cout << imprimir << std::endl;
        break;
    case Ids::ground5:
        imprimir = "bonk";
        std::cout << imprimir << std::endl;
        break;
    default:
        break;
    }*/
}
