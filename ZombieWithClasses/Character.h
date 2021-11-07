#pragma once
#include "Entity.h"
#include "GraphicManager.h"
#include "Vector2D.h"

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
            Character(Vector2F pos, Vector2F v, const char* tPath = NULL);
            Character();
            ~Character();
            void initialize(Managers::GraphicManager &g);
            void move(float t);
            void draw(Managers::GraphicManager &g);
        };
    }
}
