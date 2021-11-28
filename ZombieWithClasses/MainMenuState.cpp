#include "ScreenManager.h"
#include "MainMenuState.h"

using namespace States;
MainMenuState::MainMenuState(Managers::GraphicManager& gm) :
    Menu(gm)/*, print{false},
    tField{EM, 15, {960.0f, 50.0f}, {100, 50}}*/ {
    //GM.draw("../assets/Backgrounds/City/Bright/ciudaad.png",{0.0f,0.0f});
    //GM.drawSolidRectangle({640.0f, 250.0f}, {75, 25}, sf::Color::White);
    //BM.addButton(new Button({960.0f, -200.0f}, {400, 90}, "Zombie With Classes", [this] { setReturnCode(Managers::proceed);}, 50U, sf::Color::Green));
    BM.addButton(new Button({ 870.0f, -150.0f }, { 175, 50 }, "One Player", [this] { setReturnCode(Managers::onePlayer); }, 30U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 1050.0f, -150.0f }, { 175, 50 }, "Two Players", [this] { setReturnCode(Managers::twoPlayer); }, 30U/*, sf::Color::Red*/));
    BM.addButton(new Button({ 960.0f, -50.0f }, { 175, 50 }, "RacoonCity", [this] { setReturnCode(Managers::goRacoonCity); }, 30U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 960.0f, 50.0f }, { 175, 50 }, "Subway", [this] { setReturnCode(Managers::goSubway); }, 30U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 960.0f, 150.0f }, { 175, 50 }, "Load Game", [this] { setReturnCode(Managers::loadGame); }, 30U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 960.0f, 250.0f }, { 175, 50 }, "Exit", [this] { setReturnCode(Managers::end); }, 30U, sf::Color::Red));
    //BM.addButton(&tField);
}

int MainMenuState::execute() {
    int ret = Menu::execute();
    //    if(!print && tField.getTextDone()){
    //        print = true;
    //        std::cout << tField.getText() << std::endl;
    //    }

    GM->drawText("Zombie With Classes", { 960.0f, -250.0f }, 50U, true, sf::Color::Green);
    return ret;
}
