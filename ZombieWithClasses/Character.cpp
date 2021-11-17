#include "Character.h"
#include "GraphicManager.h"
#include "Vector2D.h"

Entities::Characters::Character::Character(Vector2F pos, Vector2F v, Ids::Ids ID, const char* tPath):
	Entity(pos, v, ID, tPath)
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

void Entities::Characters::Character::initialize(Managers::GraphicManager* GM)
{
}

void Entities::Characters::Character::draw(Managers::GraphicManager* g)
{
}
