#pragma once
#include "Enemy.h"
#include "stdafx.h"

namespace Entities
{
    namespace Characters
    {
        class Ghoul :
            public Enemy
        {
        private:

        public:
            Ghoul(Vector2F pos, Vector2F vel, const char* tPath = GHOUL_PATH);
            ~Ghoul();
            void update(float t);
            void collide(Ids::Ids idOther, Vector2F positionOther, Vector2U dimensionsOther);
        };
    }
}
