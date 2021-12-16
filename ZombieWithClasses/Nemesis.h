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
            Nemesis(Vector2F pos = { 0.0f,0.0f }, Player* p1 = nullptr, PlayerTwo* p2 = nullptr);
            Nemesis(Vector2F pos = 0, int lf = 0, Player* p1 = nullptr, PlayerTwo* p2 = nullptr);
            ~Nemesis();
            void createProjectile(Vector2F pos);
            void update(float t) override;

        };
    }
}

#endif //ZOMBIEWITHCLASSES_NEMESIS_H
