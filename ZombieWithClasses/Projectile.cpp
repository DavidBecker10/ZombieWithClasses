#include "Projectile.h"

Entities::Projectile::Projectile(sf::Vector2f pos, sf::Vector2f v, Ids::Ids ID, const char* tP)
{

}

Entities::Projectile::Projectile()
{

}

Entities::Projectile::~Projectile()
{
}

void Entities::Projectile::update(float t)
{
	position.x += vel.x * t;
}

void Entities::Projectile::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM)
{
	dimensions = static_cast<sf::Vector2u>(GM->getSize(textPath));
	scale.x = 1;
	scale.y = 1;
}

void Entities::Projectile::collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther)
{
}
