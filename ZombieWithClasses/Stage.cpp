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
    //std::cout<<"jorge"<<std::endl;
    //EL.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);
    TM->initialize(GM, &EM, &CM);
    //gerenciadorTiles.inicializar(gerenciadorGrafico, gerenciadorEventos);
    EM.setWindow(GM->getWindow());
    //gerenciadorEventos.setJanela(gerenciadorGrafico.getJanela());
    CM.setTilesManager(TM);
    //gerenciadorColisoes.setGerenciadorTiles(&gerenciadorTiles);
    CM.setList(&EL);
    player1->setEL(&EL);
    player1->setGM(GM);
}

Stage::~Stage() {
    EL.remove(player1);
    //if(player2)EL.remove(player2);
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
    //EL.update(dt);
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
        if (player1->getLife() <= 0 || player2->getLife() <= 0)
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
void States::Stage::playerNeutralized()
{
    if (player1->getLife() <= 0)
        setReturnCode(Managers::goMainMenu);
}

/*

int Stage::returnID() const{
    if (end) return Ids::Ids::endGame;
    else return Ids::Ids::proceed;
}
*/
