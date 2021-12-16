#ifndef ZOMBIEWITHCLASSES_LEADERBOARDSTATE_H
#define ZOMBIEWITHCLASSES_LEADERBOARDSTATE_H

#include "Menu.h"
#include "TextField.h"
#include "LeaderBoard.h"

namespace States
{
    class LeaderBoardState :
        public Menu
    {
    private:
        bool print;
        LeaderBoard LB;

    public:
        LeaderBoardState(Managers::GraphicManager& gm);
        int execute() override;
    };
}


#endif //ZOMBIEWITHCLASSES_LEADERBOARDSTATE_H
