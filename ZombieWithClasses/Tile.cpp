#include "Tile.h"
#include <iostream>

Tile::Tile(const Ids::Ids i, const char* p, Vector2F s):
	id{ i },
	path{ p },
	size{ s }
{
	//std::cout << path << std::endl;
}

Tile::Tile() :
	id(),
	path(),
	size(),
	GM()
{
}

Tile::~Tile()
{
}

void Tile::initialize(Managers::GraphicManager& g)
{
	//std::cout << '\t' << path << std::endl;
	g.loadTexture(path);
}

void Tile::draw(Managers::GraphicManager& g, const Vector2F position) const
{
	g.draw(path, position);
}

const Ids::Ids Tile::getID() const
{
	return id;
}

void Tile::collide(Ids::Ids idOther, Vector2F posOther, Vector2U pos)
{
}
