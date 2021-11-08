#include "Character.h"
#include "GraphicManager.h"
#include "Vector2D.h"

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
	position.x += 50000*t;
	position.y += 10000*t;
	printf("%f", position.x);
	body.setPosition(position.x, position.y);
}

void Entities::Characters::Character::draw(Managers::GraphicManager &g)
{
	g.draw(textPath, position);
}
