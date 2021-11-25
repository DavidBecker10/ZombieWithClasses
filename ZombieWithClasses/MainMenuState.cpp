//
// Created by Gabriel on 21/11/2021.
//
#include "ScreenManager.h"
#include "MainMenuState.h"
using namespace States;
MainMenuState::MainMenuState(Managers::GraphicManager& gm) :
    Menu(gm), print{ false },
    tField{ EM, 15, {640.0f, 500.0f}, {100, 50} } {
    //GM.draw("../assets/Backgrounds/City/Bright/ciudaad.png",{0.0f,0.0f});
    //GM.drawSolidRectangle({640.0f, 250.0f}, {75, 25}, sf::Color::White);
    //GM.drawText("Zombie With Classes",{640.0f, 250.0f}, 19U,true);
    BM.addButton(new Button({ 750.0f, -100.0f }, { 175, 60 }, "Zombie With Classes", [this] { setReturnCode(Managers::proceed); }, 19U, sf::Color::Green));
    BM.addButton(new Button({ 750.0f, 0.0f }, { 75, 25 }, "RacoonCity", [this] { setReturnCode(Managers::goRacoonCity); }/*, 15U, sf::Color::Green*/));
    BM.addButton(new Button({ 750.0f, 50.0f }, { 75, 25 }, "Load Game", [this] { setReturnCode(Managers::loadGame); }/*, 15U, sf::Color::Green*/));
    BM.addButton(new Button({ 750.0f, 100.0f }, { 75, 25 }, "Exit", [this] { setReturnCode(Managers::end); }, 15U, sf::Color::Red));
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
