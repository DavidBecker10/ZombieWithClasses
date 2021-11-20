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
    //CM->addCollide(this);
}

void Entities::Characters::Enemy::draw(Managers::GraphicManager* GM)
{
	GM->draw(textPath, position, scale, { 1, 9 }, { 0, 5 });
}