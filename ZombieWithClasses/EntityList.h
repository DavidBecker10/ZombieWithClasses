#pragma once
#include "List.h"
#include "Entity.h"
#include "GraphicManager.h"

namespace Lists
{
	class EntityList
	{
	private:
		List<Entities::Entity> list;

	public:
		EntityList();
		~EntityList();

		void insert(Entities::Entity* pE);

		void update(float t);
		void initialize(Managers::GraphicManager& g);
		void draw(Managers::GraphicManager& g);
		Entities::Entity* operator[](int x);
	};

}