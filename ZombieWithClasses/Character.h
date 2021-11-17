#pragma once
#include "Entity.h"
#include "Collide.h"
#include "GraphicManager.h"
#include "Vector2D.h"

namespace Entities
{
    namespace Characters
    {
        class Character :
            public Collide
        {

        public:
            Character(Vector2F pos, Vector2F v, Ids::Ids ID, const char* tPath = NULL);
            Character();
            ~Character();
            virtual void update(float t);
            virtual void initialize(Managers::GraphicManager& GM, Managers::EventManager& EM, Managers::CollisionManager& CM);
            virtual void draw(Managers::GraphicManager& g);
        };
    }
}