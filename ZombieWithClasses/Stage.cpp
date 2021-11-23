#include "ScreenManager.h"
#include "Stage.h"
#include "Enemy.h"
#include "Homer.h"
#include "Ghoul.h"

using namespace States;

Stage::Stage(Managers::GraphicManager* gm, Entities::Characters::Player* p1) :
    GM(gm),
    player1(p1),
    TM{
            {
                new Entities::Tile(Ids::empty, "../Sprites/Tiles/Platformer/Empty.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::air, "../Sprites/Tiles/Platformer/air.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground1, "../Sprites/Tiles/Platformer/Ground_01.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground2, "../Sprites/Tiles/Platformer/Ground_02.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground3, "../Sprites/Tiles/Platformer/Ground_03.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground4, "../Sprites/Tiles/Platformer/Ground_04.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground5, "../Sprites/Tiles/Platformer/Ground_05.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground6, "../Sprites/Tiles/Platformer/Ground_06.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground7, "../Sprites/Tiles/Platformer/Ground_07.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground8, "../Sprites/Tiles/Platformer/Ground_08.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground9, "../Sprites/Tiles/Platformer/Ground_09.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground10, "../Sprites/Tiles/Platformer/Ground_10.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground11, "../Sprites/Tiles/Platformer/Ground_11.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::ground12, "../Sprites/Tiles/Platformer/Ground_12.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::wallL, "../Sprites/Tiles/Platformer/wallL.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::wallR, "../Sprites/Tiles/Platformer/wallR.png", {32.0f, 32.0f}),
                new Entities::Tile(Ids::lava, "../Sprites/Tiles/PNG/Tiles_lava/lava_tile6.png", {32.0f, 32.0f}),
        },
        {32.0f, 32.0f }, "../Sprites/Maps/mapStage1.json"
},
end{ false },
clock(),
EL(),
IDCloseScreen{ EM.addListenOthers([this](const sf::Event& e) { pushCloseWindow(e); }) } {
    if (player1) EL.insert(player1);

    player1->setEL(&EL);

    EL.insert(new Entities::Characters::Homer(sf::Vector2f(400.f, 1400.f), sf::Vector2f(60.f, 30.f), Ids::Ids::Enemy));
    EL.insert(new Entities::Characters::Ghoul(sf::Vector2f(200.f, 1400.f), sf::Vector2f(60.f, 30.f), Ids::Ids::Enemy));

    EL.initialize(GM, &EM, &CM);

    TM.initialize(GM, &EM, &CM);

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
    if (dt > 0.0167) dt = 0.0167;
    clock.restart();

    EL.update(dt);
    CM.verifyCollisions();
    TM.draw(GM);
    EL.draw(GM);
    EM.manageEvent();

    if (!player1->getisLive())
        return Managers::mainMenu;

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
