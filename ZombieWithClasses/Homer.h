#pragma once
#include "Enemy.h"
#include "stdafx.h"

namespace Entities
{
    namespace Characters
    {
        class Homer :
            public Enemy
        {
        private:

        public:
            Homer(Vector2F pos, Vector2F vel, const char* tPath = HOMER_PATH);
            ~Homer();
            void update(float t);
            void collide(Ids::Ids idOther, Vector2F positionOther, Vector2U dimensionsOther);
        };
    }
}