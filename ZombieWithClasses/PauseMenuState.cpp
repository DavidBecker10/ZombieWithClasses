#include "PauseMenuState.h"
#include "ScreenManager.h"

using namespace States;
PauseMenuState::PauseMenuState(Managers::GraphicManager& gm) : Menu(gm) {
    BM.addButton(new Button({ 1150.0f, -100.0f }, { 250, 55 }, "Resume Game", [this] { setReturnCode(Managers::resume); }, 40U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 1150.0f, 0.0f }, { 250, 55 }, "Save", [this] { setReturnCode(Managers::saveGame); }, 40U/*, sf::Color::Green*/));
    BM.addButton(new Button({ 1150.0f, 100.0f }, { 250, 55 }, "Exit Game", [this] { setReturnCode(Managers::goMainMenu); }, 40U, sf::Color::Red));
}