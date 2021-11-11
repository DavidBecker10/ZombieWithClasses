#pragma once
#include "SFML/Graphics.hpp"
#include "Character.h"

namespace Managers
{
	class EventManager
	{
	private:
		sf::Event e;
		sf::RenderWindow* window;
		Entities::Characters::Character* pP1;
		Entities::Characters::Character* pP2;
		bool close;

	public:
		EventManager();
		~EventManager();

		void setWindow(sf::RenderWindow* w);
		bool checkEvent();

		void setCharacter(Entities::Characters::Character* p1, Entities::Characters::Character* p2);

		bool handleEvent();
	};
}