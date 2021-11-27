#ifndef ZOMBIEWITHCLASSES_ENTITY_H
#define ZOMBIEWITHCLASSES_ENTITY_H
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
    private:
        bool showing;
        bool faceLeft;
    protected:
        static Lists::EntityList* EL;
        Vector2F position;
        Vector2F dimensions;
        Vector2F vel;
        Vector2F scale;
        bool isActive;
        static int currentStage;

    public:
        Entity(Vector2F pos = { 0.0f, 0.0f }, Vector2F v = { 0.0f, 0.0f }, Ids::Ids ID = Ids::Ids::empty, const char* tP = nullptr);
        ~Entity();
        virtual void update(float t) = 0;
        virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM) = 0;
        virtual void draw();
        virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) = 0;

        nlohmann::json convertJSON() override;

        void setPosition(const Vector2F pos) { position = pos; }
        Vector2F getPosition() { return position; }

        void setVelocity(const Vector2F v) { vel = v; }
        Vector2F getVelocity() const { return vel; }

        Vector2F getDimensions() { return dimensions; }

        void setShowing(const bool val = true) { showing = val; }
        bool getShowing() { return showing; }

        void setFacingLeft(bool facingLeft) { faceLeft = facingLeft; }
        bool facingLeft() const { return faceLeft; }

        static void setEL(Lists::EntityList* El) { EL = El; }
        static void setStage(int stage) { currentStage = stage; }
        bool getIsActive() { return isActive; }
    };
}

#endif //ZOMBIEWITHCLASSES_ENTITY_H