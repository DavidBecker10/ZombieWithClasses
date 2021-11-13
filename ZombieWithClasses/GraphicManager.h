#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Vector2D.h"

namespace Managers
{

	class GraphicManager
	{
	private:
		sf::RenderWindow* window;
		sf::View view;
		std::map<std::string, sf::Texture*> text;

	public:
		GraphicManager();
		~GraphicManager();
		void show();
		void clear(int r = 0, int g = 0, int b = 0);
		void draw(const std::string path, const Vector2F position, sf::RectangleShape body);
		bool loadText(const std::string path);
		void initializeView();
		void center(const Vector2F center);
		sf::RenderWindow* getWindow();
		void closeWindow();
	};
}