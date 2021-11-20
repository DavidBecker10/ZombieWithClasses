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
    isGround = false;
	GM->loadTexture(textPath);
	dimensions = static_cast<sf::Vector2u>(GM->getSize(textPath));
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
    if(!isGround)
	    position.y += vel.y * t + GRAVITY;
}

void Entities::Characters::Enemy::draw(Managers::GraphicManager* GM)
{
	GM->draw(textPath, position, scale, { 1, 9 }, { 0, 5 });
}

void Entities::Characters::Enemy::collide(Ids::Ids idOutro, sf::Vector2f posicaoOutro, sf::Vector2u dimensoesOutro, bool isAbove)
{
    std::string imprimir;

    switch (idOutro) {
    case Ids::Player:
        break;
    case Ids::ground1:
        break;
    case Ids::ground2:
        isGround = true;
        break;
    case Ids::empty:
        break;
    case Ids::ground3:
        break;
    case Ids::ground4:
        break;
    case Ids::ground5:
        break;
    default:
        break;
    }
}
