#ifndef ZOMBIEWITHCLASSES_LEADERBOARDSTATE_H
#define ZOMBIEWITHCLASSES_LEADERBOARDSTATE_H

#include "Menu.h"
#include "Ent.h"
#include "TextField.h"

namespace States
{
    class LeaderboardState :
        public Menu
    {
    private:
        bool print;
        TextField tField;

    public:
        LeaderboardState(Managers::GraphicManager& gm);
        int execute() override;
    };
}

#endif //ZOMBIEWITHCLASSES_LEADERBOARDSTATE_H