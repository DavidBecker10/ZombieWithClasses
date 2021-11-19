#pragma once
#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Vector2D.h"

namespace Managers
{
    class GraphicManager {
    private:
        sf::RenderWindow* window;
        sf::View view;
        std::map<const std::string, sf::Texture*> textures;
        sf::Texture* text;
        sf::Sprite sprite;

    public:
        GraphicManager();
        ~GraphicManager();
        void show() const;
        void clear(int r = 0, int g = 0, int b = 0);
        void draw(const std::string& path, const sf::Vector2f pos, sf::Sprite body);
        void draw(const std::string& path, const sf::Vector2f position, sf::Sprite body, sf::Vector2f scale, const sf::Vector2u nFrames, const sf::Vector2u frame);
        bool loadTexture(const std::string& path);
        void centralize(const sf::Vector2f centro);
        sf::RenderWindow* getWindow() const;
        const sf::Vector2f getSize(const std::string& path) const;
        void initializeView();
    };
}