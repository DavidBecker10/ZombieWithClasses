#include "Character.h"
#include "GraphicManager.h"

Entities::Characters::Character::Character(sf::Vector2f pos, sf::Vector2f v, const char* tPath):
Entity(pos, v),
textPath(tPath),
text()
{
}

Entities::Characters::Character::Character():
Entity(),
textPath(),
text()
{
}
//a
Entities::Characters::Character::~Character()
{
}

void Entities::Characters::Character::initialize(Managers::GraphicManager &g)
{
	g.loadText(textPath);
}

void Entities::Characters::Character::move(float t)
{
	position.x += vel.x;
	position.y += vel.y;
}

void Entities::Characters::Character::draw(Managers::GraphicManager &g)
{
	g.draw(textPath, position);
}
