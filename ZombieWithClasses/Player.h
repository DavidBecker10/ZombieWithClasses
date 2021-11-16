#pragma once
#include "Character.h"
#include "GraphicManager.h"
#include "EventManager.h"
#include "CollisionManager.h"
#include "Vector2D.h"
#include "Ids.h"

namespace Entities
{
	namespace Characters
	{
		class Player :
			public Character
		{
		private:
			unsigned int listenKey;

		public:
			Player(Vector2F pos, Vector2F vel, const char* tPath = NULL, int h = 100);
			Player();
			~Player();
			void initialize(Managers::GraphicManager& GM, Managers::EventManager& EM, Managers::CollisionManager& CM);
			void update(float t);
			void draw(Managers::GraphicManager& g);
			void handleEvents(const sf::Event& e);
			void collide(Ids::Ids idOutro, Vector2F posicaoOutro, Vector2F dimensoesOutro);
		};
	}
}