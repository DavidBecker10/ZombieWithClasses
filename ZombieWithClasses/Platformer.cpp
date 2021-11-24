#include "Platformer.h"

Entities::Obstacles::Platformer::Platformer() :
	Obstacle()
{
}

Entities::Obstacles::Platformer::~Platformer()
{
}

void Entities::Obstacles::Platformer::update(float t)
{
}

void Entities::Obstacles::Platformer::initialize(Managers::EventManager* EM, Managers::CollisionManager* CM)
{
}

void Entities::Obstacles::Platformer::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther)
{
}

void Entities::Obstacles::Platformer::collidePlayer(Entities::Characters::Player* pP)
{
	pP->setIsGround(true);
}
