#pragma once
#include "Entity.h"
//#include "GraphicManager.h"
//#include "Vector2D.h"
//#include "CollisionManager.h"
#include "EntityList.h"

namespace Entities
{
    namespace Characters
    {
        class Character :public Entity
        {
        protected:
            bool isGround;
            Lists::EntityList* EL;

        public:
            Character(Vector2F pos = { 0.0f, 0.0f }, Vector2F v = { 0.0f, 0.0f }, Ids::Ids ID = Ids::Ids::empty, const char* tPath = nullptr);
            ~Character();
            virtual void update(float t);
            void setEL(Lists::EntityList* El);
            Lists::EntityList* getEL();
            virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);
            virtual void draw(Managers::GraphicManager* g);
            virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) = 0;
        };
    }
}