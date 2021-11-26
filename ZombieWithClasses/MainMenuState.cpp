#include "ScreenManager.h"
#include "MainMenuState.h"
using namespace States;
MainMenuState::MainMenuState(Managers::GraphicManager& gm) :
    Menu(gm), print{ false },
    tField{ EM, 15, {640.0f, 500.0f}, {100, 50} }
{
    BM.addButton(new Button({ 750.0f, -100.0f }, { 175, 60 }, "Zombie With Classes", [this] { setReturnCode(Managers::proceed); }, 19U, sf::Color::Green));
    BM.addButton(new Button({ 750.0f, 0.0f }, { 75, 25 }, "RacoonCity", [this] { setReturnCode(Managers::goRacoonCity); }/*, 15U, sf::Color::Green*/));
    BM.addButton(new Button({ 750.0f, 50.0f }, { 75, 25 }, "Load Game", [this] { setReturnCode(Managers::loadGame); }/*, 15U, sf::Color::Green*/));
    BM.addButton(new Button({ 750.0f, 100.0f }, { 75, 25 }, "Exit", [this] { setReturnCode(Managers::end); }, 15U, sf::Color::Red));
    BM.addButton(new Button({ 700.0f, 150.0f }, { 75, 25 }, "One Player", [this] { setReturnCode(Managers::onePlayer); }, 15U, sf::Color::Red));
    BM.addButton(new Button({ 800.0f, 150.0f }, { 75, 25 }, "Two Players", [this] { setReturnCode(Managers::twoPlayers); }, 15U, sf::Color::Red));
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
