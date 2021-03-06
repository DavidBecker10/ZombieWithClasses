#include "Character.h"
#include "GraphicManager.h"
#include "TileMap.h"
#include "Vector2D.h"
#include "Ent.h"

Lists::EntityList* Entities::Characters::Character::EL = NULL;

Entities::Characters::Character::Character(Vector2F pos, Ids::Ids ID, const char* tPath, int lf) :
	Entity(pos, { 0.0f,0.0f }, ID, tPath, lf), isGround(false)
{
}

Entities::Characters::Character::~Character()
{
}

void Entities::Characters::Character::update(float t)
{
}

void Entities::Characters::Character::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM)
{
	dimensions = GM->getSize(textPath);
	scale.x = 1;
	scale.y = 1;
}

void Entities::Characters::Character::draw()
{
}

