/*
#ifndef ZOMBIEWITHCLASSES_COLLIDE_H
#define ZOMBIEWITHCLASSES_COLLIDE_H

#include "Draw.h"
#include "DrawID.h"
#include "Vector2D.h"

namespace Base {
    class Collide : public Draw {
    public:
        Collide(Vector2F position = { 0.0f, 0.0f }, Vector2F vel = { 0.0f, 0.0f }, DrawID::DrawID ID = DrawID::noID, const char* pathTexture = nullptr);
        virtual void collide(DrawID::DrawID idOther, Vector2F positionOther, Vector2F dimensionsOther) = 0;
    };
}

#endif //ZOMBIEWITHCLASSES_COLLIDE_H
*/