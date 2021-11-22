#pragma once
#include "List.h"
#include "Entity.h"
#include "GraphicManager.h"

class CollisionManager;

namespace Lists
{
	class EntityList
	{
	private:
		Lists::List<Entities::Entity> list;

	public:
		EntityList();
		~EntityList();

		void insert(Entities::Entity* pE);
		void remove(Entities::Entity* pE);
		int getSize();

		void update(float t);
		void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM);
		void draw(Managers::GraphicManager* g);
		Entities::Entity* operator[](int x);
		void destroyEntities();
	};

}