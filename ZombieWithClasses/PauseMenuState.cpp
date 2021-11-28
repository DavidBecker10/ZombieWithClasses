#include "PauseMenuState.h"
#include "ScreenManager.h"
using namespace States;
PauseMenuState::PauseMenuState(Managers::GraphicManager& gm) : Menu(gm) {
    BM.addButton(new Button({ 960.0f, -200.0f }, { 200, 75 }, "Resume", [this] { setReturnCode(Managers::resume); }, 40U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 960.0f, 0.0f }, { 200, 75 }, "Save", [this] { setReturnCode(Managers::saveGame); }, 40U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 960.0f, 200.0f }, { 200, 75 }, "Exit Game", [this] { setReturnCode(Managers::goMainMenu); }, 40U, sf::Color::Red));

}
