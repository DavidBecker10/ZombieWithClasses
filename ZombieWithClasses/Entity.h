#pragma once

#include "Ent.h"
#include "GraphicManager.h"
#include "EventManager.h"
#include "Serialize.h"
namespace Managers {
    class CollisionManager;
}
namespace Lists {
    class EntityList;
}
namespace Entities
{
    class Entity :
        public Ent, public Serialize
    {
    protected:
        float frame;
        int energy;
        Vector2F position;
        Vector2F dimensions;
        Vector2F vel;
        Vector2F scale;
        Vector2F adjusts;
        static int currentStage;

    public:
        Entity(Vector2F pos = { 0.0f, 0.0f }, Vector2F v = { 0.0f, 0.0f }, Ids::Ids ID = Ids::Ids::empty, const char* tP = nullptr, int lf = 0);
        ~Entity();
        virtual void update(float t) = 0;
        virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM) = 0;
        virtual void draw();
        virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) = 0;
        virtual void adjust();
        virtual nlohmann::json convertJSON() override;
        Vector2F getPosition() { return position; }
        Vector2F getDimensions() { return dimensions; }
        static void setStage(int stage) { currentStage = stage; }
        static int getStage() { return currentStage; }
        int getEnergy() { return energy; }
    };
}