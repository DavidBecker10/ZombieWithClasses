#include "stdafx.h"
#include "ScreenManager.h"
#include "Stage.h"
#include "Enemy.h"
#include "Homer.h"
using namespace States;

Stage::Stage(Managers::GraphicManager* gm, Managers::TilesManager* tm, Managers::ScreenManager* sm, Entities::Characters::PlayerOne* p1) :
    GM(gm),
    player1{ p1 },
    player2{ NULL },
    TM{ tm },
    SM{ sm },
    IDCloseScreen{ EM.addListenOthers([this](const sf::Event& e) { pushCloseWindow(e); }) },
    IDPushPause{ EM.addListenKeyboard([this](const sf::Event& e) { pushPause(e); }) },
    returnCode(Managers::proceed)
{
    TM->initialize(GM, &EM, &CM);

    EM.setWindow(GM->getWindow());

    CM.setTilesManager(TM);

    CM.setList(&EL);
    player1->setEL(&EL);
    player1->setGM(GM);
}

Stage::~Stage() {
    EL.remove(player1);
    EL.destroyEntities();
    delete TM;
}

int Stage::execute() {
    returnCode = Managers::proceed;
    double t = clock.getTime();
    if (t > 0.0167)t = 0.0167;
    clock.resetClock();

    EM.manageEvent();
    EL.update(t);
    CM.verifyCollisions();
    TM->draw(GM);
    EL.draw();
    if (!player2) {
        playerNeutralized();
        if (player1->getIsEnd())
            returnCode = Managers::goMainMenu;
        GM->centralize(player1->getPosition());
    }
    else
    {
        if (!player1->getIsActive() || !player2->getIsActive())
            returnCode = Managers::goMainMenu;

        Vector2F aux;
        aux.x = (player1->getPosition().x < player2->getPosition().x) ? (player1->getPosition().x) : (player2->getPosition().x);
        aux.y = (player1->getPosition().y < player2->getPosition().y) ? (player1->getPosition().y) : (player2->getPosition().y);
        Vector2F center;
        center.x = fabs(player1->getPosition().x - player2->getPosition().x) / 2 + aux.x;
        center.y = fabs(player1->getPosition().y - player2->getPosition().y) / 2 + aux.y;
        GM->centralize(center);
    }
    return returnCode;
}

void Stage::pushCloseWindow(const sf::Event e) {
    if (e.type == sf::Event::Closed) setReturnCode(Managers::end);
}

void Stage::pushPause(const sf::Event e) {
    if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Key::Escape) {
        setReturnCode(Managers::goPauseMenu);
        clock.pauseClock();
    }
}
void States::Stage::playerNeutralized()
{
    if (!player1->getIsActive())
       setReturnCode(Managers::goMainMenu);
}

/*
int Stage::returnID() const{
    if (end) return Ids::Ids::endGame;
    else return Ids::Ids::proceed;
}
*/
