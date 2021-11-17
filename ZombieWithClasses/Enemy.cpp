#include "Enemy.h"

Entities::Characters::Enemy::Enemy(Vector2F pos, Vector2F vel, Ids::Ids ID, const char* tPath) :
	Character(pos, vel, ID, tPath)
{
}

Entities::Characters::Enemy::Enemy()
{
}

Entities::Characters::Enemy::~Enemy()
{
}

void Entities::Characters::Enemy::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM)
{
	printf("oi");
	GM->loadTexture(textPath);
	dimensions = GM->getSize(textPath);
}

void Entities::Characters::Enemy::update(float t)
{
	if (position.y < 200)
	{
		position.x += vel.x * t;
		position.y += 50000 * t;
	}
}

void Entities::Characters::Enemy::draw(Managers::GraphicManager* GM)
{
	GM->draw(textPath, position);
}

void Entities::Characters::Enemy::collide(Ids::Ids idOutro, Vector2F posicaoOutro, Vector2F dimensoesOutro)
{
    std::string imprimir;

    switch (idOutro) {
    case Ids::Enemy:
        imprimir = "ai ui ui";
        break;
    case Ids::ground1:
        imprimir = "fui ludibriado";
        break;
    case Ids::ground2:
        imprimir = "cai";
        break;
    case Ids::empty:
        imprimir = "mano o que ta acontecendo";
        break;
    case Ids::ground3:
        imprimir = "pontudo";
        break;
    case Ids::ground4:
        imprimir = "estou livre";
        break;
    case Ids::ground5:
        imprimir = "bonk";
        break;
    default:
        break;
    }

    std::cout << imprimir << std::endl;
}
