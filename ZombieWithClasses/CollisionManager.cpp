#include "CollisionManager.h"
#include <cmath>

void Managers::CollisionManager::checkCollision(Lists::EntityList& EL)
{
	Vector2F posA, posB;
	float distance;

	for (int i = 0; i < EL.getSize(); i++)
	{
		posA = EL[i]->getPosition();
		for (int j = i + 1; j < EL.getSize(); j++)
		{
			posB = EL[j]->getPosition();

			distance = sqrt(pow((posA.x - posB.x), 2) + pow((posA.y - posB.y), 2));  //distancia entre dois pontos
			if (distance <= 100)
			{
				EL.remove(EL[j]);
			}
		}
	}
}
