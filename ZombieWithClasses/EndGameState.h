#ifndef ZOMBIEWITHCLASSES_ENDGAMESTATE_H
#define ZOMBIEWITHCLASSES_ENDGAMESTATE_H

#include "Menu.h"
#include "TextField.h"

namespace States
{
	class EndGameState :
		public Menu
	{
	private:
		bool print;
		TextField tField;
	public:
		EndGameState(Managers::GraphicManager& gm);
		int execute() override;
	};
}

#endif //ZOMBIEWITHCLASSES_ENDGAMESTATE_H
