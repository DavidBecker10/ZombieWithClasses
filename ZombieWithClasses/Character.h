#pragma once
#include "Entity.h"
#include "GraphicManager.h"
#include "Vector2D.h"
#include "CollisionManager.h"

namespace Entities
{
    namespace Characters
    {
        class Character :
            public Entity
        {
        protected:
            sf::Vector2f scale;

        public:
            Character(sf::Vector2f pos, sf::Vector2f v, Ids::Ids ID, const char* tPath = NULL);
            Character();
            ~Character();
            virtual void update(float t);
            virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM);
            virtual void draw(Managers::GraphicManager* g);
            virtual void collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2f dimensionsOther) = 0;
        };
    }
}