//
// Created by Gabriel on 18/11/2021.
//
#include "stdafx.h"
#include "ScreenManager.h"
#include "Stage.h"
#include "Enemy.h"
#include "Homer.h"
using namespace States;

Stage::Stage(Managers::GraphicManager* gm, Managers::TilesManager* tm, Entities::Characters::PlayerOne* p1) :
    GM(gm),
    player1{ p1 },
    TM{ tm },
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
    //sf::Time t = clock.getElapsedTime();
    double t = clock.getTime();
    //float dt = t.asSeconds();
    //if(dt>0.0167)dt=0.0167;
    //clock.restart();
    if (t > 0.0167)t = 0.0167;
    clock.resetClock();


    EM.manageEvent();
    EL.update(t);
    CM.verifyCollisions();
    TM->draw(GM);
    EL.draw();

    return returnCode;
}

/**sf::Time t = clock.getElapsedTime();
clock.restart();

EM.manageEvent();
EL.update(t.asSeconds());
CM.verifyCollisions();

TM.draw(GM);
EL.draw(&GM);

}*/



void Stage::pushCloseWindow(const sf::Event e) {
    if (e.type == sf::Event::Closed) setReturnCode(Managers::end);
}

void Stage::pushPause(const sf::Event e) {
    if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Key::Escape) {
        setReturnCode(Managers::goPauseMenu);
        clock.pauseClock();
    }
}
/*

int Stage::returnID() const{
    if (end) return Ids::Ids::endGame;
    else return Ids::Ids::proceed;
}
*/
