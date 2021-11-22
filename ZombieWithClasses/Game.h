#pragma once
#include "Stage.h"
#include "ScreenManager.h"

class Game
{
private:
    Managers::GraphicManager GM;
    Entities::Characters::Player player1;
    Managers::ScreenManager SM;
    bool end;
    States::Stage* fase;

public:
    Game();
    ~Game();
    void execute();
};