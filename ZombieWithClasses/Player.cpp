#include "Player.h"

Entities::Characters::Player::Player(Vector2F pos, Vector2F vel, const char* tPath, int h) :
	Character(pos, vel, tPath),
	hp(h)
{
}

Entities::Characters::Player::Player() :
	Character(),
	hp()
{
}

Entities::Characters::Player::~Player()
{
}

void Entities::Characters::Player::moveUp()
{
	position.y -= 5.0f;
}

void Entities::Characters::Player::moveLeft()
{
	position.x -= 5.0f;
}

void Entities::Characters::Player::moveDown()
{
	position.y += 5.0f;
}

void Entities::Characters::Player::moveRight()
{
	position.x += 5.0f;
}
