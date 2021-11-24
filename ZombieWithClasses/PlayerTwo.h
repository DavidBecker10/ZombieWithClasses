#pragma once
#include "Player.h"
#include "stdafx.h"

namespace Entities
{
    namespace Characters
    {
        class PlayerTwo :
            public Player
        {
        public:
            PlayerTwo(Vector2F pos = { 0.0f, 0.0f }, const char* path = PLAYER2_PATH);
            ~PlayerTwo();
            void handleEvents(const sf::Event& e);
        };
    }
}


