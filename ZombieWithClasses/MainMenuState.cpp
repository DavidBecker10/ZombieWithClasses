#include "ScreenManager.h"
#include "MainMenuState.h"

using namespace States;
MainMenuState::MainMenuState(Managers::GraphicManager& gm) :
    Menu(gm), print{ false },
    tField{ EM, 15, {640.0f, 250.0f}, {100, 50} } {
    //GM.draw("../assets/Backgrounds/City/Bright/ciudaad.png",{0.0f,0.0f});
    BM.addButton(new Button({ 640.0f, 350.0f }, { 75, 25 }, "RacoonCity", [this] { setReturnCode(Managers::goRacoonCity); }/*, 15U, sf::Color::Green*/));
    BM.addButton(new Button({ 640.0f, 450.0f }, { 50, 25 }, "Exit", [this] { setReturnCode(Managers::end); }, 15U, sf::Color::Red));
    BM.addButton(&tField);
}

int MainMenuState::execute() {
    int ret = Menu::execute();
    if (!print && tField.getTextDone()) {
        print = true;
        std::cout << "Marcelo caralho enfia o pastelao no cu: " << tField.getText() << std::endl;
    }
    return ret;
}
