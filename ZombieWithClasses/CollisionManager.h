#pragma once
#include "Player.h"
#include "EntityList.h"
#include "GraphicManager.h"

namespace Managers
{
	class CollisionManager
	{
	private:
		Managers::GraphicManager* GM;

	public:
		void setGraphicManager(Managers::GraphicManager* g) { GM = g; }
		void checkCollision(Lists::EntityList& EL);

	};

}