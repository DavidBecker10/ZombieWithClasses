#ifndef JSON_HPP_ENDGAMESTATE_H
#define JSON_HPP_ENDGAMESTATE_H


#include "Menu.h"
#include "TextField.h"
#include "LeaderBoard.h"

namespace States
{
    class EndGameState :
        public Menu
    {
    private:
        bool print;
        TextField tField;
        LeaderBoard LB;
        int score;

    public:
        EndGameState(Managers::GraphicManager& gm, int scr);
        int execute() override;
    };
}



#endif //JSON_HPP_ENDGAMESTATE_H
