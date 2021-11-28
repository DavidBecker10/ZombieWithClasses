#ifndef ZOMBIEWITHCLASSES_ENDGAMESTATE_H
#define ZOMBIEWITHCLASSES_ENDGAMESTATE_H

#include "Menu.h"
#include "TextField.h"
#include "Leaderboard.h"

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

#endif //ZOMBIEWITHCLASSES_ENDGAMESTATE_H
