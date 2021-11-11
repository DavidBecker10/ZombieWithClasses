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
	position.x += vel.x*t;
	position.y += vel.y*t;
	body.setPosition(position.x, position.y);
}

void Entities::Characters::Character::moveUp()
{
	position.y -= 5.0f;
}

void Entities::Characters::Character::moveLeft()
{
	position.x -= 5.0f;
}

void Entities::Characters::Character::moveDown()
{
	position.y += 5.0f;
}

void Entities::Characters::Character::moveRight()
{
	position.x += 5.0f;
}