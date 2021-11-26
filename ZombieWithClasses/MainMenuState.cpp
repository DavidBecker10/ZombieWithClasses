#include "ScreenManager.h"
#include "MainMenuState.h"
using namespace States;
MainMenuState::MainMenuState(Managers::GraphicManager& gm) :
    Menu(gm), print{ false },
    tField{ EM, 15, {640.0f, 500.0f}, {100, 50} }
{
    BM.addButton(new Button({ 1150.0f, -300.0f }, { 500, 90 }, "Zombie With Classes", [this] { setReturnCode(Managers::proceed); }, 50U, sf::Color::Green));
    BM.addButton(new Button({ 1000.0f, -200.0f }, { 250, 55 }, "One Player", [this] { setReturnCode(Managers::onePlayer); }, 40U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 1300.0f, -200.0f }, { 250, 55 }, "Two Players", [this] { setReturnCode(Managers::twoPlayers); }, 40U/*, sf::Color::Red*/));
    BM.addButton(new Button({ 1150.0f, -100.0f }, { 250, 55 }, "RacoonCity", [this] { setReturnCode(Managers::goRacoonCity); }, 40U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 1150.0f, 0.0f }, { 250, 55 }, "Load Game", [this] { setReturnCode(Managers::loadGame); }, 40U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 1150.0f, 100.0f }, { 250, 55 }, "Exit", [this] { setReturnCode(Managers::end); }, 40U, sf::Color::Red));
    BM.addButton(&tField);
}

int MainMenuState::execute() {
    int ret = Menu::execute();
    if (!print && tField.getTextDone()) {
        print = true;
       // std::cout << tField.getText() << std::endl;
    }
    return ret;
}
