#ifndef ZOMBIEWITHCLASSES_GHOUL_H
#define ZOMBIEWITHCLASSES_GHOUL_H

#include "Enemy.h"
#include "Rock.h"
namespace Entities {
    namespace Characters {
        class Ghoul : public Enemy {
        private:
            Rock* rock;
            float attackCooldown;

        public:
            Ghoul(Vector2F pos = { 0.0f,0.0f }, Player* p1 = nullptr, PlayerTwo* p2 = nullptr);
            Ghoul(Vector2F pos = 0, int lf = 0, Player* p1 = nullptr, PlayerTwo* p2 = nullptr);
            ~Ghoul();
            void update(float t) override;
            void createProjectile(Vector2F pos);

        };
    }
}

#endif //ZOMBIEWITHCLASSES_GHOUL_H
