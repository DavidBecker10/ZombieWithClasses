#pragma once
#include "Player.h"
#include "stdafx.h"

namespace Entities
{
    namespace Characters
    {
        class PlayerOne :
            public Player
        {
        public:
            PlayerOne(Vector2F pos = { 0.0f, 0.0f }, const char* path = PLAYER_PATH);
            ~PlayerOne();
            void handleEvents(const sf::Event& e);
        };
    }
}

