#ifndef ZOMBIEWITHCLASSES_GHOUL_H
#define ZOMBIEWITHCLASSES_GHOUL_H

#include "Enemy.h"

namespace Entities {
    namespace Characters {
        class Ghoul : public Enemy {
        private:
            //float jumpTime;
            //bool isJumping;
            //static const float attackTime;
        public:
            Ghoul(Vector2F pos = { 0.0f,0.0f }, Player* p1 = nullptr);
            Ghoul(Vector2F pos, int lf, Player* p1);
            ~Ghoul();
            void update(float t) override;
            //            void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
        };
    }
}

#endif //ZOMBIEWITHCLASSES_GHOUL_H
