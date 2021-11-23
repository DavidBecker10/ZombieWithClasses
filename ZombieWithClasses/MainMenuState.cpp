#include "MainMenuState.h"
#include "ScreenManager.h"

using namespace States;
MainMenuState::MainMenuState(Managers::GraphicManager* gm) :
    Menu(gm), print{ false },
    tField{ EM, 15, {640.0f, 200.0f}, {100, 50} } {
    BM.addButton(new Button({ 640.0f, 350.0f }, { 100, 50 }, "RacoonCity", [this] { setReturnCode(Managers::goRacoonCity); }/*, 15U, sf::Color::Green*/));
    BM.addButton(new Button({ 640.0f, 450.0f }, { 300, 50 }, "Exit", [this] { setReturnCode(Managers::end); }, 15U, sf::Color::Red));
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
