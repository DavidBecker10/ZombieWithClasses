#ifndef ZOMBIEWITHCLASSES_PLAYERTWO_H
#define ZOMBIEWITHCLASSES_PLAYERTWO_H

#include "Player.h"
namespace Entities {
    namespace Characters {
        class PlayerTwo : public Player {
        public:
            PlayerTwo(Vector2F pos = { 0.0f, 0.0f });
            ~PlayerTwo();
            void handleEvents(const sf::Event& e);
            void centralizeInView();
        };
    }
}

#endif //ZOMBIEWITHCLASSES_PLAYERTWO_H
