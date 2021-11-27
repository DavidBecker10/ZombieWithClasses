#ifndef ZOMBIEWITHCLASSES_PLAYERTWO_H
#define ZOMBIEWITHCLASSES_PLAYERTWO_H
#include "Character.h"
#include "Projectile.h"
#include "PlayerOne.h"

namespace Entities
{
	namespace Characters
	{
		class PlayerTwo :public PlayerOne
		{

		public:
			PlayerTwo(Vector2F pos = { 0.0f, 0.0f });
			~PlayerTwo();
			void handleEvents(const sf::Event& e);
			void createProjectile(Ids::Ids id, Vector2F pos, const char* path);
			void centralizeInView();
		};
	}
}

#endif //ZOMBIEWITHCLASSES_PLAYERTWO_H