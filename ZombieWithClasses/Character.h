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

        public:
            Character(Vector2F pos, Vector2F v, const char* tPath = NULL);
            Character();
            ~Character();
            virtual void update(float t);
        };
    }
}