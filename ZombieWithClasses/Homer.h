#ifndef ZOMBIEWITHCLASSES_HOMER_H
#define ZOMBIEWITHCLASSES_HOMER_H
#include "Player.h"
#include "Enemy.h"
#include "stdafx.h"
namespace Entities {
    namespace Characters {
        class Homer : public Enemy {

        public:
            Homer(Vector2F pos = { 0.0f,0.0f }, Player* p1 = nullptr);
            Homer(Vector2F pos, int lf, Player* p1);
            ~Homer();
            void update(float t) override;
            //void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
        };
    }
}
#endif //ZOMBIEWITHCLASSES_HOMER_H
