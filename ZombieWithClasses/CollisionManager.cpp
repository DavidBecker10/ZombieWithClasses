#include "CollisionManager.h"

void Managers::CollisionManager::checkCollision(Lists::EntityList& EL)
{
	for (int i = 0; i < EL.getSize(); i++)
	{
		for (int j = i + 1; j < EL.getSize(); j++)
		{
			if (EL[i]->getPosition() == EL[j]->getPosition())
			{
				std::cout << "Colidiu" << std::endl;
			}
		}
	}
}
