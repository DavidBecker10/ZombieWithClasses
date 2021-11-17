#ifndef ZOMBIEWITHCLASSES_COLLIDE_H
#define ZOMBIEWITHCLASSES_COLLIDE_H

#include "Entity.h"
#include "Ids.h"
#include "Vector2D.h"

class Collide : public Entities::Entity {
public:
    Collide(Vector2F position = { 0.0f, 0.0f }, Vector2F vel = { 0.0f, 0.0f }, Ids::Ids ID = Ids::empty, const char* pathTexture = nullptr);
    virtual ~Collide();
    virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) = 0;
};

#endif //ZOMBIEWITHCLASSES_COLLIDE_H
