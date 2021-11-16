#include "Character.h"
#include "GraphicManager.h"
#include "Vector2D.h"

Entities::Characters::Character::Character(Vector2F pos, Vector2F v, const char* tPath):
Entity(pos, v, tPath)
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
	if (position.y <  100)
	{
		position.x += vel.x * t;
		position.y += 70000 * t;
	}
}