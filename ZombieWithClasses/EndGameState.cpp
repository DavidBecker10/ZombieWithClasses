#include "EndGameState.h"
#include "ScreenManager.h"

States::EndGameState::EndGameState(Managers::GraphicManager& gm):
	Menu(gm), tField(EM, 15, { 960.0f, 50.0f }, { 300.0f, 50.0f }, 30U), print(false)
{
    BM.addButton(&tField);
	BM.addButton(new Button({ 960.0f, 250.0f }, { 400, 75 }, "Return to Main Menu", [this] { setReturnCode(Managers::goMainMenu); }, 40U, sf::Color::Red));
}

int States::EndGameState::execute()
{
    int ret = Menu::execute();
    if(!print && tField.getTextDone()){
        print = true;
        std::cout << tField.getText() << std::endl;
    }

    GM->drawText("Zombie With Classes", { 960.0f, -250.0f }, 50U, true, sf::Color::Green);
    GM->drawText("End Game", { 960.0f, -100.0f }, 50U, true, sf::Color::White);
    GM->drawText("Your Name:", { 960.0f, 0.0f }, 30U, true, sf::Color::White);
    return ret;
}
