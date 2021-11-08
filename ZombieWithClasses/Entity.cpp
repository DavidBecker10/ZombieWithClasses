#include "Entity.h"

Entities::Entity::Entity(Vector2F pos, Vector2F v, const char* tP):
	Ent(),
	position(pos),
	vel(v),
	text(),
	body(),
	textPath(tP)
{

}

Entities::Entity::Entity():
	Ent(),
	position(),
	vel(),
	text(),
	body(),
	textPath()
{
}

Entities::Entity::~Entity()
{
}

void Entities::Entity::initialize(Managers::GraphicManager& g)
{
	g.loadText(textPath);
}

void Entities::Entity::draw(Managers::GraphicManager& g)
{
	g.draw(textPath, position);
}
