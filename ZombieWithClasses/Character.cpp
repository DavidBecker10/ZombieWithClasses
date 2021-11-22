#include "Character.h"
#include "GraphicManager.h"
#include "TileMap.h"
#include "Vector2D.h"

Entities::Characters::Character::Character(sf::Vector2f pos, sf::Vector2f v, Ids::Ids ID, const char* tPath):
	Entity(pos, v, ID, tPath),
	isGround(false)
{
}

Entities::Characters::Character::Character():
	Entity(),
	isGround(false)
{
}

Entities::Characters::Character::~Character()
{
}

void Entities::Characters::Character::update(float t)
{
	//position += vel * t;
}

void Entities::Characters::Character::setEL(Lists::EntityList* El)
{
	EList = El;
}

Lists::EntityList* Entities::Characters::Character::getEL()
{
	return EList;
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
