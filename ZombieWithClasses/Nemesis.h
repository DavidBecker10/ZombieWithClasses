#ifndef ZOMBIEWITHCLASSES_NEMESIS_H
#define ZOMBIEWITHCLASSES_NEMESIS_H

#include "Enemy.h"
#include "Player.h"
#include "Bone.h"

namespace Entities {
    namespace Characters {
        class Nemesis : public Enemy {
        private:
            Bone* bone;
            float attackFrame;

        public:
            Nemesis(Vector2F pos = { 0.0f,0.0f }, Player* p1 = nullptr);
            Nemesis(Vector2F pos, int lf, Player* p1);
            ~Nemesis();
            void createProjectile(Vector2F pos);
            void update(float t) override;
            void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
        };
    }
}

#endif //ZOMBIEWITHCLASSES_NEMESIS_H
