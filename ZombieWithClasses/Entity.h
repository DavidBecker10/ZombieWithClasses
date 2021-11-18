#pragma once
#include "SFML/Graphics.hpp"
#include "Ent.h"
#include "Ids.h"
#include "Vector2D.h"
#include "GraphicManager.h"
#include "EventManager.h"

class CollisionManager;

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
        Ids::Ids id;

    public:
        Entity(Vector2F pos, Vector2F v, Ids::Ids ID, const char* tP);
        Entity();
        ~Entity();
        virtual void update(float t) = 0;
        virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM) = 0;
        virtual void draw(Managers::GraphicManager* g);
        Vector2F getPosition() { return position; }
        Vector2F getDimensions() { return dimensions; }
        Ids::Ids getID() { return id; }
        const char* getTextPath() { return textPath; }
        virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) = 0;
    };
}