//
// Created by Gabriel on 23/11/2021.
//

#include "PauseMenuState.h"
#include "ScreenManager.h"
using namespace States;
PauseMenuState::PauseMenuState(Managers::GraphicManager& gm) : Menu(gm) {
    BM.addButton(new Button({ 750.0f, -100.0f }, { 75, 25 }, "Resume Game", [this] { setReturnCode(Managers::resume); }/*, 15U, sf::Color::Green*/));
    BM.addButton(new Button({ 750.0f, -50.0f }, { 75, 25 }, "Save", [this] { setReturnCode(Managers::saveGame); }/*, 15U, sf::Color::Green*/));
    BM.addButton(new Button({ 750.0f, 0.0f }, { 75, 25 }, "Exit Game", [this] { setReturnCode(Managers::goMainMenu); }, 15U, sf::Color::Red));

}
