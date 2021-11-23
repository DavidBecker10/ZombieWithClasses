#include"Ids.h"
#include "Menu.h"
#include"ScreenManager.h"

States::Menu::Menu(Managers::GraphicManager& gm) :
    returnCode(Managers::proceed), BM(EM, gm), GM(gm) {
    //GM.centralize(GM.getWindowSize() * Vector2F(0.5f,0.5f));
    EM.setWindow(GM.getWindow());

}

States::Menu::~Menu() {

}

int States::Menu::execute() {
    returnCode = Managers::proceed;
    EM.manageEvent();
    BM.draw();
    return returnCode;
}

