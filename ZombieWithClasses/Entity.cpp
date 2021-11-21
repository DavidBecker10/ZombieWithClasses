#include "Entity.h"
#include "CollisionManager.h"

Entities::Entity::Entity(sf::Vector2f pos, sf::Vector2f v, Ids::Ids ID, const char* tP) :
	Ent(ID),
	position(pos),
	vel(v),
	scale(sf::Vector2f(1, 1)),
	textPath(tP)
{
	this->ID = ID;
}

Entities::Entity::Entity():
	Ent(),
	position(),
	vel(),
	textPath()
{
}

Entities::Entity::~Entity()
{
}

void Entities::Entity::draw(Managers::GraphicManager* g)
{
	g->draw(textPath, position);
}
