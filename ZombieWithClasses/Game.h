#pragma once
#include "Stage.h"
#include "ScreenManager.h"

class Game
{
private:
    Managers::GraphicManager GM;
    Entities::Characters::PlayerOne player1;
    Managers::ScreenManager SM;
    bool end;

public:
    Game();
    ~Game();
    void execute();
};