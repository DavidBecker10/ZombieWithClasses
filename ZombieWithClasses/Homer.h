#ifndef ZOMBIEWITHCLASSES_HOMER_H
#define ZOMBIEWITHCLASSES_HOMER_H
#include "Player.h"
#include "Enemy.h"
#include "stdafx.h"
namespace Entities {
    namespace Characters {
        class Homer : public Enemy {

        public:
            Homer(Vector2F pos = { 0.0f,0.0f }, Player* p1 = nullptr, PlayerTwo* p2 = nullptr);
            Homer(Vector2F pos = 0, int lf = 0, Player* p1 = nullptr, PlayerTwo* p2 = nullptr);
            ~Homer();
            void update(float t) override;

        };
    }
}
#endif //ZOMBIEWITHCLASSES_HOMER_H
