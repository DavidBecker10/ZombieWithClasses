#ifndef ZOMBIEWITHCLASSES_GAME_H
#define ZOMBIEWITHCLASSES_GAME_H

#include "Stage.h"
#include "ScreenManager.h"

class Game
{
private:
    Managers::GraphicManager GM;
    Managers::ScreenManager SM;
    bool end;

public:
    Game();
    ~Game();
    void execute();
};

#endif //ZOMBIEWITHCLASSES_GAME_H