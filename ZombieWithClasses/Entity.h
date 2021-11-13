#pragma once
#include "SFML/Graphics.hpp"
#include "Ent.h"
#include "Vector2D.h"
#include "GraphicManager.h"

namespace Entities
{
    class Entity :
        public Ent
    {
    protected:
        sf::RectangleShape body;
        Vector2F position;
        Vector2F vel;
        const char* textPath;

    public:
        Entity(Vector2F pos, Vector2F v, const char* tP);
        Entity();
        ~Entity();
        virtual void update(float t) = 0;
        void initialize(Managers::GraphicManager& g);
        void draw(Managers::GraphicManager& g);
        Vector2F getPosition() { return position; }
        const char* getTextPath() { return textPath; }
        sf::FloatRect getBounds() { return body.getGlobalBounds(); }
    };
}