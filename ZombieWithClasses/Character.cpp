#include "Character.h"
#include "GraphicManager.h"

Entities::Characters::Character::Character(Vector2F pos, Vector2F v, const char* tPath):
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

Entities::Characters::Character::~Character()
{
}

void Entities::Characters::Character::initialize(Managers::GraphicManager &g)
{
	g.loadText(textPath);
}

void Entities::Characters::Character::move(float t)
{
	position.x += 0.1*t;
	position.y += 0.005;
	body.setPosition(position.x, position.y);
}

void Entities::Characters::Character::draw(Managers::GraphicManager &g)
{
	g.draw(textPath, position);
}
