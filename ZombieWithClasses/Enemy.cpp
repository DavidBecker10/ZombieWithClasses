#include "Enemy.h"

Entities::Characters::Enemy::Enemy(Vector2F pos, Vector2F vel, Ids::Ids ID, const char* tPath) :
	Character(pos, vel, ID, tPath)
{
}

Entities::Characters::Enemy::Enemy()
{
}

Entities::Characters::Enemy::~Enemy()
{
}

void Entities::Characters::Enemy::update(float t)
{
	if (position.y < 200)
	{
		position.x += vel.x * t;
		position.y += 50000 * t;
	}
}
