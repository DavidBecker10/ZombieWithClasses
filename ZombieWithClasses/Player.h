#pragma once
#include "Character.h"
#include "GraphicManager.h"
#include "EventManager.h"
#include "CollisionManager.h"
#include "Vector2D.h"
#include "Ids.h"
#include "TilesManager.h"

namespace Entities
{
	namespace Characters
	{
		class Player :
			public Character
		{
		private:
			unsigned int listenKey;
			TilesManager* TM;

		public:
			Player(Vector2F pos, Vector2F vel, Ids::Ids ID, const char* tPath = NULL);
			Player();
			~Player();
			void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM);
			void setTM(TilesManager* TM);
			void update(float t);
			void draw(Managers::GraphicManager* g);
			void handleEvents(const sf::Event& e);
			void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
		};
	}
}