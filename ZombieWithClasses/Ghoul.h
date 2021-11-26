#ifndef ZOMBIEWITHCLASSES_GHOUL_H
#define ZOMBIEWITHCLASSES_GHOUL_H

#include "Enemy.h"

namespace Entities {
    namespace Characters {
        class Ghoul : public Enemy {
        private:
            sf::Clock c;
        public:
            Ghoul(Vector2F pos = { 0.0f,0.0f }, Vector2F vel = { 0.0f,0.0f });
            Ghoul(nlohmann::json j);
            ~Ghoul();
            void update(float t) override;
            void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
        };
    }
}

#endif //ZOMBIEWITHCLASSES_GHOUL_H