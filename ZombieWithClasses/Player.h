#pragma once
#include "Character.h"
#include "stdafx.h"
#include "TilesManager.h"
#include "Bullet.h"
#include "json.hpp"

namespace Entities
{
	namespace Characters
	{
		class PlayerTwo;
		class Player :public Character
		{
		private:
			PlayerTwo* p2;
		protected:
			int score;
			unsigned int listenKey;
			bool isJumping;
			bool isEnd;
			Bullet* bullet;
			float frameSHOT;

			//Managers::TilesManager* TM;
		public:
			Player(Vector2F pos = { 0.0f, 0.0f }, const char* path = PLAYER_PATH, Ids::Ids id = Ids::Ids::Player);
			~Player();
			void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);
			//void setTM(Managers::TilesManager* TM);
			void update(float t);
			void draw();
			virtual void handleEvents(const sf::Event& e);
			void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
			void createProjectile(Vector2F pos);
			void initializeJSON(nlohmann::json j);
			void centralizeInView();
			bool getIsEnd() { return isEnd; }
			int getScore() { return score; }
			void setScore(int scr) { score = scr; }
			void incrementScore(int scr) { score += scr; }
			void setPlayer2(PlayerTwo* pl2) { p2 = pl2; }
			nlohmann::json convertJSON() override;
		};
	}
}