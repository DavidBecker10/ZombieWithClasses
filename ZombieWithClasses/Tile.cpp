#include "Tile.h"
#include <iostream>

Entities::Tile::Tile(const Ids::Ids i, const char* p, sf::Vector2f s):
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

void Entities::Tile::draw(Managers::GraphicManager& g, const sf::Vector2f position) const
{
	g.draw(path, position, body);
}

const Ids::Ids Entities::Tile::getID() const
{
	return id;
}

sf::Vector2f Entities::Tile::getSize() const
{
	return size;
}

void Entities::Tile::setPosition(sf::Vector2f pos)
{
	position = pos;
}

sf::Vector2f Entities::Tile::getPosition() const
{
	return position;
}

void Entities::Tile::collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther)
{
    switch (idOther) {
    case Ids::Enemy:
		/*...*/
        break;
    case Ids::Player:
		/*...*/
        break;
    default:
        break;
    }
}
