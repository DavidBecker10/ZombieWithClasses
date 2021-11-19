#include "Character.h"
#include "GraphicManager.h"
#include "TileMap.h"
#include "Vector2D.h"

Entities::Characters::Character::Character(sf::Vector2f pos, sf::Vector2f v, Ids::Ids ID, const char* tPath):
	Entity(pos, v, ID, tPath),
	scale(sf::Vector2f(1, 1))
{
}

Entities::Characters::Character::Character():
	Entity()
{
}

Entities::Characters::Character::~Character()
{
}

void Entities::Characters::Character::update(float t)
{
	//position += vel * t;
}

void Entities::Characters::Character::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM)
{
	dimensions = static_cast<sf::Vector2u>(GM->getSize(textPath));
	scale.x = 1;
	scale.y = 1;
}

void Entities::Characters::Character::draw(Managers::GraphicManager* g)
{
}
