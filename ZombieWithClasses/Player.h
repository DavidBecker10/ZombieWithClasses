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
			bool isJumping;
			TilesManager* TM;

		public:
			Player(sf::Vector2f pos, sf::Vector2f vel, Ids::Ids ID, const char* tPath = NULL);
			Player();
			~Player();
			void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM);
			void setTM(TilesManager* TM);
			void update(float t);
			void draw(Managers::GraphicManager* g);
			void handleEvents(const sf::Event& e);
			void collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther);
			void died();
		};
	}
}