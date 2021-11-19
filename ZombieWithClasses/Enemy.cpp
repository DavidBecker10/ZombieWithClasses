#include "Enemy.h"
#include "stdafx.h"

Entities::Characters::Enemy::Enemy(sf::Vector2f pos, sf::Vector2f vel, Ids::Ids ID, const char* tPath) :
	Character(pos, vel, ID, tPath)
{
}

Entities::Characters::Enemy::Enemy()
{
}

Entities::Characters::Enemy::~Enemy()
{
}

void Entities::Characters::Enemy::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM)
{
	//printf("oi");
	GM->loadTexture(textPath);
	dimensions = GM->getSize(textPath);
    CM->addCollide(this);
}

void Entities::Characters::Enemy::update(float t)
{
    if (position.x < 1555.f)
        position.x += vel.x * t;
    else {
        vel.x *= -1;
        scale.x = -1;
    }
    if(position.x > 76)
        position.x += vel.x * t;
    else {
        vel.x *= -1;
        scale.x = 1;
    }
    if(position.y < 1444.f)
	    position.y += vel.y * t + GRAVITY;
}

void Entities::Characters::Enemy::draw(Managers::GraphicManager* GM)
{
	GM->draw(textPath, position, body, scale, { 1, 9 }, { 0, 5 });
}

void Entities::Characters::Enemy::collide(Ids::Ids idOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro)
{
    std::string imprimir;


    /*switch (idOutro) {
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
