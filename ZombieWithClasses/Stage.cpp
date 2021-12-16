#include "stdafx.h"
#include "ScreenManager.h"
#include "Stage.h"
#include "Enemy.h"
#include "Homer.h"

using namespace States;

Stage::Stage(Managers::GraphicManager* gm, Managers::TilesManager* tm, Entities::Characters::Player* p1) :
    GM(gm),
    player1{ p1 },
    player2{ nullptr },
    TM{ tm },
    IDCloseScreen{ EM.addListenOthers([this](const sf::Event& e) { pushCloseWindow(e); }) },
    IDPushPause{ EM.addListenKeyboard([this](const sf::Event& e) { pushPause(e); }) },
    returnCode(Managers::proceed)
{

    TM->initialize(GM, &EM, &CM);

    EM.setWindow(GM->getWindow());

    CM.setTilesManager(TM);

    CM.setList(&EL);
    Entities::Characters::Player::setEL(&EL);
    Entities::Characters::Player::setGM(GM);
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
        if (player1->getIsEnd() && player1->getStage() == 1) {
            playerScore = player1->getScore();
            returnCode = Managers::goSubway;
        }
        else if (player1->getIsEnd())
        {
            playerScore = player1->getScore();
            returnCode = Managers::goEndGame;
        }
        if (player1->getEnergy() <= 0) {
            playerScore = player1->getScore();
            returnCode = Managers::goEndGame;
        }
        GM->centralize(player1->getPosition());
    }
    else
    {
        if ((player1->getIsEnd() || player2->getIsEnd()) && player1->getStage() == 1)
        {
            playerScore = player1->getScore();
            returnCode = Managers::goSubway;
        }
        else if (player1->getIsEnd() || player2->getIsEnd()) {
            playerScore = player1->getScore();
            returnCode = Managers::goEndGame;
        }
        if (player1->getEnergy() <= 0 || player2->getEnergy() <= 0) {
            playerScore = player1->getScore();
            returnCode = Managers::goEndGame;
        }
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
int States::Stage::playerScore = 0;

