#ifndef ZOMBIEWITHCLASSES_PAUSEMENUSTATE_H
#define ZOMBIEWITHCLASSES_PAUSEMENUSTATE_H

#include "Menu.h"

namespace States {
    class PauseMenuState : public Menu {
    public:
        PauseMenuState(Managers::GraphicManager& gm);
    };
}

#endif //ZOMBIEWITHCLASSES_PAUSEMENUSTATE_H
