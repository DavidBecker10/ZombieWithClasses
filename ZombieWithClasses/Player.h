#pragma once
#include "Character.h"
#include "Vector2D.h"

namespace Entities
{
	namespace Characters
	{
		class Player :
			public Character
		{
		private:
			int hp;

		public:
			Player(Vector2F pos, Vector2F vel, const char* tPath = NULL, int h = 100);
			Player();
			~Player();
			void moveUp();
			void moveLeft();
			void moveDown();
			void moveRight();
		};
	}
}