#ifndef ZOMBIEWITHCLASSES_PROJECTILE_H
#define ZOMBIEWITHCLASSES_PROJECTILE_H


#include "Entity.h"

namespace Entities {
    class Projectile : public Entity {
    protected:
        bool dir;
    public:
        Projectile(Vector2F pos = { 0.0f, 0.0f }, Vector2F v = { 0.0f, 0.0f }, Ids::Ids i = Ids::Ids::empty, const char* tP = nullptr, bool dir = true);
        virtual ~Projectile();

        virtual void update(float t);
        void draw();
        void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);
        virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
        nlohmann::json convertJSON() override;
    };
}

#endif //ZOMBIEWITHCLASSES_PROJECTILE_H


