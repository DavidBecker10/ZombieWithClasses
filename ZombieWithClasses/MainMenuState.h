#pragma once
#include "Menu.h"
#include "TextField.h"

namespace States
{
    class MainMenuState :
        public Menu
    {
    private:
        bool print;
        TextField tField;

    public:
        MainMenuState(Managers::GraphicManager* gm);
        int execute() override;
    };
}
