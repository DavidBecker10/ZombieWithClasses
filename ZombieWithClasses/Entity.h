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

        sf::Vector2f position;
        sf::Vector2f vel;
        sf::Vector2f dimensions;
        sf::Sprite body;
        const char* textPath;
        Ids::Ids id;

    public:
        Entity(sf::Vector2f pos, sf::Vector2f v, Ids::Ids ID, const char* tP);
        Entity();
        ~Entity();
        virtual void update(float t) = 0;
        virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM) = 0;
        virtual void draw(Managers::GraphicManager* g);
        sf::Vector2f getPosition() { return position; }
        sf::Vector2f getDimensions() { return dimensions; }
        Ids::Ids getID() { return id; }
        const char* getTextPath() { return textPath; }
        virtual void collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2f dimensionsOther) = 0;
    };
}