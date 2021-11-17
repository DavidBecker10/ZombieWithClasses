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

        public:
            Character(Vector2F pos, Vector2F v, Ids::Ids ID, const char* tPath = NULL);
            Character();
            ~Character();
            virtual void update(float t);
            virtual void initialize(Managers::GraphicManager* GM);
            virtual void draw(Managers::GraphicManager* g);
            virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) = 0;
        };
    }
}