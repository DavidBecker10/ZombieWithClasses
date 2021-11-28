#ifndef ZOMBIEWITHCLASSES_MAINMENUSTATE_H
#define ZOMBIEWITHCLASSES_MAINMENUSTATE_H

#include "TextField.h"
#include "Menu.h"

namespace States {

    class MainMenuState : public Menu {
    private:
        //bool print;
        //TextField tField;

    public:
        MainMenuState(Managers::GraphicManager& gm);
        int execute() override;
    };

}

#endif //ZOMBIEWITHCLASSES_MAINMENUSTATE_H
