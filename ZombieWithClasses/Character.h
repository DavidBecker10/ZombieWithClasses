#pragma once
#include "Entity.h"
#include "EntityList.h"

namespace Entities
{
    namespace Characters
    {
        class Character :public Entity
        {
        protected:
            bool isGround;
            bool faceLeft;
            static Lists::EntityList* EL;


        public:
            Character(Vector2F pos = { 0.0f, 0.0f }, Ids::Ids ID = Ids::Ids::empty, const char* tPath = nullptr, int lf = 0);
            ~Character();
            virtual void update(float t);
            virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);
            virtual void draw();
            virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) = 0;
            virtual nlohmann::json convertJSON() = 0;
            bool facingLeft() const { return faceLeft; }
            static void setEL(Lists::EntityList* El) { EL = El; }
        };
    }
}