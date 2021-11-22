#include "Projectile.h"

Entities::Projectile::Projectile(sf::Vector2f pos, sf::Vector2f v, Ids::Ids ID, const char* tP, bool dir):
	Entity(pos, v, ID, tP)
{
	dir == true ? scale = sf::Vector2f(1, 1) : scale = sf::Vector2f(-1, 1);
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

void Entities::Projectile::draw(Managers::GraphicManager* g)
{
	g->loadTexture(textPath);
	dimensions = static_cast<sf::Vector2u>(g->getSize(textPath));
	g->draw(textPath, position, scale, { 1, 9 }, { 0, 5 });
}

void Entities::Projectile::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM)
{
	GM->loadTexture(textPath);
	dimensions = static_cast<sf::Vector2u>(GM->getSize(textPath));
}

void Entities::Projectile::collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther)
{
	switch (idOther) {
	case Ids::Enemy:
		break;
	default:
		break;
	}
}
