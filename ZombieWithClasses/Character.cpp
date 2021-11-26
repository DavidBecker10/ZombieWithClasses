#include "Character.h"
#include "GraphicManager.h"
#include "TileMap.h"
#include "Vector2D.h"
#include "EntityList.h"

Entities::Characters::Character::Character(Vector2F pos, Vector2F v, Ids::Ids ID, const char* tPath) :
	Entity(pos, v, ID, tPath), isGround(false)
{
}

Entities::Characters::Character::~Character()
{
}

void Entities::Characters::Character::update(float t)
{
	//position += vel * t;
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

//void Entities::Characters::Character::setEL(Lists::EntityList *El) {
//    EL = El;
//}
//
//Lists::EntityList *Entities::Characters::Character::getEL() {
//    return EL;
//}
