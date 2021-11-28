#include "LeaderboardState.h"
#include "ScreenManager.h"
#include "ScreenManager.h"
#include <sstream>

States::LeaderboardState::LeaderboardState(Managers::GraphicManager& gm):
    Menu(gm)
{
    BM.addButton(new Button({ 960.0f, 300.0f }, { 175, 50 }, "Return", [this] { setReturnCode(Managers::goMainMenu); }, 30U, sf::Color::Red));
}

int States::LeaderboardState::execute()
{
    int ret = Menu::execute();
    GM->drawText("LEADERBOARD", { 960.0f, -300.0f }, 50U, true, sf::Color::Green);

    Vector2F pos = {850.0f, -250.0f };

    std::multimap<unsigned int, std::string> scores = LB.getRanking();
    std::multimap<unsigned int, std::string>::reverse_iterator it;
    int i = 0;
    for (it = scores.rbegin(); it != scores.rend() && i < 10; ++it) {
        GM->drawText(it->second, pos, 30U, true, sf::Color::White);
        std::stringstream ss;
        ss << it->first;
        std::string s;
        ss >> s;
        GM->drawText(s, {pos.x + 200.0f, pos.y}, 30U, true, sf::Color::White);
        pos.y += 50.0f;
        i++;
    }
    return ret;
}
