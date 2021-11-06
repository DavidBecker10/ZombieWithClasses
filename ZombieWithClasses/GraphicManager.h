#pragma once
#include <SFML/Graphics.hpp>
#include <string>

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
		void draw(const std::string path, const sf::Vector2f position);
		bool loadText(const std::string path);
		void center(const sf::Vector2f center);
		sf::RenderWindow* getWindow();
		void closeWindow();
	};
}//a