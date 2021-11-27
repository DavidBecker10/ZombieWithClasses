#ifndef ZOMBIEWITHCLASSES_PLAYERONE_H
#define ZOMBIEWITHCLASSES_PLAYERONE_H
#include "Character.h"
#include "TilesManager.h"
#include "Projectile.h"
#include "json.hpp"
#include "stdafx.h"

namespace Entities
{
	namespace Characters
	{
		class PlayerOne :public Character
		{
		protected:
			unsigned int listenKey;
			bool isJumping;
			bool isLive;
			bool isEnd;
			Managers::TilesManager* TM;
			Projectile* bullet;

		public:
			PlayerOne(Vector2F pos = { 0.0f, 0.0f }, const char* path = PLAYER_PATH, Ids::Ids id = Ids::Player1);
			~PlayerOne();
			void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);
			void setTM(Managers::TilesManager* TM);
			void update(float t);
			void draw();
			virtual void handleEvents(const sf::Event& e);
			void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
			virtual void createProjectile(Ids::Ids id, Vector2F pos, const char* path);
			void centralizeInView();
			void initializeJSON(nlohmann::json j);
			bool getIsLive() { return isLive; }
			bool getIsEnd() { return isEnd; }
		};
	}
}

#endif //ZOMBIEWITHCLASSES_PLAYERONE_H