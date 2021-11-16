#pragma once
#include "SFML/Graphics.hpp"
#include "Ent.h"
#include "Vector2D.h"
#include "GraphicManager.h"
#include "EventManager.h"
#include "CollisionManager.h"

namespace Entities
{
    class Entity :
        public Ent
    {
    protected:
        Vector2F position;
        Vector2F vel;
        Vector2F dimensions;
        const char* textPath;

    public:
        Entity(Vector2F pos, Vector2F v, const char* tP);
        Entity();
        ~Entity();
        virtual void update(float t) = 0;
        virtual void initialize(Managers::GraphicManager& GM, Managers::EventManager& EM, Managers::CollisionManager& CM);
        virtual void draw(Managers::GraphicManager& g);
        Vector2F getPosition() { return position; }
        const char* getTextPath() { return textPath; }
    };
}