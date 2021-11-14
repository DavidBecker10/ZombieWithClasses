#pragma once
#include "Character.h"

namespace Entities
{
    namespace Characters
    {
        class Enemy :
            public Character
        {
        private:


        public:
            Enemy(Vector2F pos, Vector2F vel, const char* tPath = NULL);
            Enemy();
            ~Enemy();
            void update(float t);
        };
    }
}
