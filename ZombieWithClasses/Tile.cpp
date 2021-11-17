#include "Tile.h"
#include <iostream>

Entities::Tile::Tile(const Ids::Ids i, const char* p, Vector2F s):
	Entity(),
	id{ i },
	path{ p },
	size{ s },
	gm{},
	cm{}
{
	
}

Entities::Tile::Tile() :
	id(),
	path(),
	size(),
	cm(),
	gm()
{
}

Entities::Tile::~Tile()
{
}

void Entities::Tile::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM)
{
	gm = GM;
	//cm = CM;
	gm->loadTexture(path);
}

void Entities::Tile::update(float t)
{
}

void Entities::Tile::draw(Managers::GraphicManager& g, const Vector2F position) const
{
	g.draw(path, position);
}

const Ids::Ids Entities::Tile::getID() const
{
	return id;
}

void Entities::Tile::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther)
{
}
