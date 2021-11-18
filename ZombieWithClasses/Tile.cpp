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

void Entities::Tile::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM)
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

Vector2F Entities::Tile::getSize() const
{
	return size;
}

void Entities::Tile::setPosition(Vector2F pos)
{
	position = pos;
}

Vector2F Entities::Tile::getPosition() const
{
	return position;
}

void Entities::Tile::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther)
{
    std::string imprimir;

    switch (idOther) {
    case Ids::Enemy:
        imprimir = "ai ui ui";
		std::cout << imprimir << std::endl;
        break;
    case Ids::Player:
        imprimir = "jogador bateu";
		std::cout << imprimir << std::endl;
        break;
    default:
        break;
    }
}
