#include "ScreenManager.h"
#include "MainMenuState.h"

using namespace States;
MainMenuState::MainMenuState(Managers::GraphicManager& gm) :
    Menu(gm)
{
    BM.addButton(new Button({ 870.0f, -150.0f }, { 175, 50 }, "One Player", [this] { setReturnCode(Managers::onePlayer); }, 30U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 1050.0f, -150.0f }, { 175, 50 }, "Two Players", [this] { setReturnCode(Managers::twoPlayer); }, 30U/*, sf::Color::Red*/));
    BM.addButton(new Button({ 960.0f, -60.0f }, { 175, 50 }, "RacoonCity", [this] { setReturnCode(Managers::goRacoonCity); }, 30U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 960.0f, 30.0f }, { 175, 50 }, "Subway", [this] { setReturnCode(Managers::goSubway); }, 30U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 960.0f, 120.0f }, { 175, 50 }, "Load Game", [this] { setReturnCode(Managers::loadGame); }, 30U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 960.0f, 210.0f }, { 175, 50 }, "Leaderboard", [this] { setReturnCode(Managers::goLeaderboard); }, 30U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 960.0f, 300.0f }, { 175, 50 }, "Exit", [this] { setReturnCode(Managers::end); }, 30U, sf::Color::Red));
}

int MainMenuState::execute() {
    int ret = Menu::execute();

    GM->drawText("Zombie With Classes", { 960.0f, -250.0f }, 50U, true, sf::Color::Green);
    return ret;
}
