#pragma once

#include "Stage.h"
#include "ScreenManager.h"
#include "PlayerOne.h"

class Game
{
private:
    Managers::GraphicManager GM;
    Entities::Characters::PlayerOne player1;
    Entities::Characters::PlayerTwo player2;
    Managers::ScreenManager SM;
    bool end;

public:
    Game();
    ~Game();
    void execute();
};