#include "Lava.h"

Entities::Obstacles::Lava::Lava() :
	Obstacle()
{
}

Entities::Obstacles::Lava::~Lava()
{
}

void Entities::Obstacles::Lava::update(float t)
{
}

void Entities::Obstacles::Lava::initialize(Managers::EventManager* EM, Managers::CollisionManager* CM)
{
}

void Entities::Obstacles::Lava::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther)
{
}

/*
void Entities::Obstacles::Lava::collidePlayer(Entities::Characters::Player* pP)
{
	EL->remove(pP);
}
*/