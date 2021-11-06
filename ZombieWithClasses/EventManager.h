#pragma once
#include "SFML/Graphics.hpp"

namespace Managers
{
	class EventManager
	{
	private:
		sf::Event e;
		sf::RenderWindow* window;
		bool close;

	public:
		EventManager();
		~EventManager();

		void setWindow(sf::RenderWindow* w);
		bool checkEvent();

		bool handleEvent();
	};
}//a