#ifndef ZOMBIEWITHCLASSES_BULLET_H
#define ZOMBIEWITHCLASSES_BULLET_H

#include "Projectile.h"

namespace Entities {
    class Bullet : public Projectile {
    public:
        Bullet(Vector2F pos = { 0.0f, 0.0f }, Vector2F v = { 0.0f, 0.0f }, bool dir = false, int dmg = 0);
        Bullet(nlohmann::json j, bool dir = false);
        ~Bullet();
        //       void update(float t) override;
               /* void draw();
                void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);*/
        void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
    };
}

#endif //ZOMBIEWITHCLASSES_BULLET_H
