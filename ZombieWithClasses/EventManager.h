#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"

namespace Managers
{
	class EventManager
	{
	private:
		sf::Event e;
		sf::RenderWindow* window;
		Entities::Characters::Player* pP1;
		Entities::Characters::Player* pP2;
		bool close;

	public:
		EventManager();
		~EventManager();

		void setWindow(sf::RenderWindow* w);
		bool checkEvent();

		void setCharacter(Entities::Characters::Player* p1, Entities::Characters::Player* p2);

		bool handleEvent();
	};
}