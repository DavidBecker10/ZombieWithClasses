#pragma once
#include "Entity.h"
#include "GraphicManager.h"

namespace Entities
{
    namespace Characters
    {
        class Character :
            public Entity
        {
        protected:
            const char* textPath;
            sf::Texture* text;
            sf::Sprite body;

        public:
            Character(sf::Vector2f pos, sf::Vector2f v, const char* tPath = NULL);
            Character();
            ~Character();
            void initialize(Managers::GraphicManager &g);
            void move(float t);
            void draw(Managers::GraphicManager &g);
        };
    }
}
//a