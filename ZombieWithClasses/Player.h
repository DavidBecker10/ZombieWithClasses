#pragma once
#include "Character.h"
//#include "GraphicManager.h"
//#include "EventManager.h"
//#include "CollisionManager.h"
//#include "Vector2D.h"
//#include "Ids.h"
#include "TilesManager.h"
#include "Projectile.h"

namespace Entities
{
	namespace Characters
	{
		class Player :public Character
		{
		protected:
			unsigned int listenKey;
			bool isJumping;
			Managers::TilesManager* TM;

		public:
			Player(Vector2F pos = { 0.0f, 0.0f }, const char* path = NULL);
			~Player();
			void initialize(Managers::EventManager* EM, Managers::CollisionManager* CM);
			void setTM(Managers::TilesManager* TM);
			void update(float t);
			void draw();
			virtual void handleEvents(const sf::Event& e) = 0;
			void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
			void createProjectile(Ids::Ids id, Vector2F pos, const char* path);
			void neutralized();
		};
	}
}