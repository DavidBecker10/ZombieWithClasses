#include "SpiderWeb.h"

Entities::Obstacles::SpiderWeb::SpiderWeb() :
	Obstacle()
{
}

Entities::Obstacles::SpiderWeb::~SpiderWeb()
{
}

void Entities::Obstacles::SpiderWeb::update(float t)
{
}

void Entities::Obstacles::SpiderWeb::initialize(Managers::EventManager* EM, Managers::CollisionManager* CM)
{
}

void Entities::Obstacles::SpiderWeb::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther)
{
}

void Entities::Obstacles::SpiderWeb::collidePlayer(Entities::Characters::Player* pP)
{
	pP->setVelocity(Vector2F(0.5, 0.5));
}
