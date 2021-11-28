#include "LeaderboardState.h"
#include "ScreenManager.h"
#include "ScreenManager.h"

States::LeaderboardState::LeaderboardState(Managers::GraphicManager& gm):
    Menu(gm), tField{ EM, 15, {960.0f, 50.0f}, {100, 50} }
{
    BM.addButton(new Button({ 960.0f, 300.0f }, { 175, 50 }, "Return", [this] { setReturnCode(Managers::goMainMenu); }, 30U, sf::Color::Red));
    BM.addButton(&tField);
}

int States::LeaderboardState::execute()
{
    int ret = Menu::execute();
        if(!print && tField.getTextDone()){
            print = true;
            std::cout << tField.getText() << std::endl;
        }

    GM->drawText("Zombie With Classes", { 960.0f, -250.0f }, 50U, true, sf::Color::Green);
    return ret;
}
