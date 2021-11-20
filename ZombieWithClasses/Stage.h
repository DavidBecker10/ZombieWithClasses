#pragma once
#include "EntityList.h"
#include "TilesManager.h"
#include "Tile.h"


namespace Stages{
	class Stage :
		public Ent
	{
	protected:
		Lists::EntityList* Elist;
		TilesManager* TM;

	private:
		Stage();
		~Stage();
		virtual void makeMap() = 0;
		void update(float t);
	};
}