#include "stdafx.h"
#include "ScreenManager.h"
#include "Stage.h"
#include "Enemy.h"
#include "Homer.h"

using namespace States;

Stage::Stage(Managers::GraphicManager* gm, Entities::Characters::Player* p1) :
    GM(gm),
    player1{ p1 },
    TM{
            {
                new Entities::Tile(Ids::empty, "../Assets/Tiles/Platformer/Empty.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::air, "../Assets/Tiles/Platformer/air.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground1, "../Assets/Tiles/Platformer/Ground_01.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground2, "../Assets/Tiles/Platformer/Ground_02.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground3, "../Assets/Tiles/Platformer/Ground_03.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground4, "../Assets/Tiles/Platformer/Ground_04.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground5, "../Assets/Tiles/Platformer/Ground_05.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground6, "../Assets/Tiles/Platformer/Ground_06.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground7, "../Assets/Tiles/Platformer/Ground_07.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground8, "../Assets/Tiles/Platformer/Ground_08.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground9, "../Assets/Tiles/Platformer/Ground_09.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground10, "../Assets/Tiles/Platformer/Ground_10.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground11, "../Assets/Tiles/Platformer/Ground_11.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground12, "../Assets/Tiles/Platformer/Ground_12.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::wallL, "../Assets/Tiles/Platformer/wallL.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::wallR, "../Assets/Tiles/Platformer/wallR.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::lava, "../Assets/Tiles/PNG/Tiles_lava/lava_tile6.png", {32.0f, 32.0f}),
            },
            {32.0f, 32.0f}, RACOON_PATH
},
end{ false },
clock(),
EL(),
IDCloseScreen{ EM.addListenOthers([this](const sf::Event& e) { pushCloseWindow(e); }) } {

    if (player1) EL.insert(player1);
    player1->setEL(&EL);
    player1->setGM(GM);

    EL.insert(new Entities::Characters::Homer(Vector2F(200.f, 3000.f), Vector2F(60.0f, 30.0f)));
    EL.insert(new Entities::Characters::Homer(Vector2F(300.f, 3000.f), Vector2F(60.0f, 30.0f)));
    EL.initialize(&EM, &CM);
    TM.initialize(&EM, &CM);
    EM.setWindow(GM->getWindow());
    CM.setTilesManager(&TM);
    CM.setList(&EL);
}

Stage::~Stage() {
    EL.remove(player1);
    EL.destroyEntities();
}

int Stage::execute() {
    sf::Time t = clock.getElapsedTime();
    float dt = t.asSeconds();
    if (dt > 0.0167) dt = 0.0167f;
    clock.restart();

    EL.update(dt);
    CM.verifyCollisions();
    TM.draw(GM);
    EL.draw();
    EM.manageEvent();

    if (end) return Managers::end;
    else return Managers::proceed;
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
    if (e.type == sf::Event::Closed) end = true;
}
/*

int Stage::returnID() const{
    if (end) return Ids::Ids::endGame;
    else return Ids::Ids::proceed;
}
*/
