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
        //sf::View view;
        std::map<const std::string, sf::Texture*> textures;
        sf::Texture* text;
        sf::Sprite sprite;

    public:
        GraphicManager();
        ~GraphicManager();
        void show() const;
        void clear(int r = 0, int g = 0, int b = 0);
        void draw(const std::string& path, const Vector2F pos);
        void draw(const std::string& path, const Vector2F position, const Vector2U nFrames, const Vector2U frame);
        bool loadTexture(const std::string& path);
        void centralize(const Vector2F centro);
        sf::RenderWindow* getWindow() const;
        const Vector2F getSize(const std::string& path) const;
        void initializeView();

    };
}