#pragma once

#include "Ent.h"
//#include "Vector2D.h"
#include "GraphicManager.h"
#include "EventManager.h"

namespace Managers {
    class CollisionManager;
}
namespace Entities
{
    class Entity :
        public Ent
    {
    private:
        bool showing;
        bool faceLeft;
    protected:
        Vector2F position;
        Vector2F dimensions;
        Vector2F vel;
        Vector2F scale;

    public:
        Entity(Vector2F pos = { 0.0f, 0.0f }, Vector2F v = { 0.0f, 0.0f }, Ids::Ids ID = Ids::Ids::empty, const char* tP = nullptr);
        ~Entity();
        virtual void update(float t) = 0;
        virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM) = 0;
        virtual void draw(Managers::GraphicManager* g);
        virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) = 0;

        void setPosition(const Vector2F pos) { position = pos; }
        Vector2F getPosition() { return position; }

        void setVelocity(const Vector2F v) { vel = v; }
        Vector2F getVelocity() const { return vel; }

        Vector2F getDimensions() { return dimensions; }

        void setShowing(const bool val = true) { showing = val; }
        bool getShowing() { return showing; }

        void setFacingLeft(bool facingLeft) { faceLeft = facingLeft; }
        bool facingLeft() const { return faceLeft; }

    };
}