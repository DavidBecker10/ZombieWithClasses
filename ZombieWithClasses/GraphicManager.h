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
        sf::Font font;

    public:
        GraphicManager();
        ~GraphicManager();
        void show() const;
        void clear(int r = 0, int g = 0, int b = 0);
        void draw(const std::string& path, Vector2F pos);
        void draw(const std::string& path, Vector2F pos, Vector2F scale);
        void draw(const std::string& path, Vector2F position, Vector2U nFrames, Vector2U frame);
        bool loadTexture(const std::string& path);
        void centralize(Vector2F centro);
        sf::RenderWindow* getWindow() const;
        const Vector2F getSize(const std::string& path) const;
        void initializeView();
        void drawSolidRectangle(Vector2F center, Vector2F dimensions, const sf::Color color);
        void drawText(const std::string text, Vector2F position, unsigned int size, const bool centralize = true) const;
        Vector2F getMousePosition() const;
        Vector2F getWindowSize() const { return{ view.getSize().x, view.getSize().y }; }
        const Vector2F getSizeView() const { return Vector2F(view.getSize().x, view.getSize().y); }
        const Vector2F getCenterView() const { return Vector2F(view.getCenter().x, view.getCenter().y); }
    };
}