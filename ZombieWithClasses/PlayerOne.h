#pragma once
#include "Character.h"
#include "TilesManager.h"
#include "Projectile.h"
#include "json.hpp"
namespace Entities
{
	namespace Characters
	{
		class PlayerOne :public Character
		{
		private:
			unsigned int listenKey;
			bool isJumping;
			bool isLive;
			bool isEnd;
			Managers::TilesManager* TM;
			Projectile* bullet;

		public:
			PlayerOne(Vector2F pos = { 0.0f, 0.0f });
			~PlayerOne();
			void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);
			void setTM(Managers::TilesManager* TM);
			void update(float t);
			void draw();
			void handleEvents(const sf::Event& e);
			void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
			void createProjectile(Ids::Ids id, Vector2F pos, const char* path);
			void centralizeInView();
			void initializeJSON(nlohmann::json j);
			bool getIsLive() { return isLive; }
			bool getIsEnd() { return isEnd; }
		};
	}
}