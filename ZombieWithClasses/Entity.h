#pragma once
#include "SFML/Graphics.hpp"
#include "Ent.h"
#include "Vector2D.h"

namespace Entities
{
    class Entity :
        public Ent
    {
    protected:
        Vector2F position;
        Vector2F vel;

    public:
        Entity(Vector2F pos, Vector2F v);
        Entity();
        ~Entity();
        virtual void move(float t) = 0;
    };
}