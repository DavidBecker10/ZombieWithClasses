#include "Player.h"
#include "CollisionManager.h"
#include "Ids.h"

Entities::Characters::Player::Player(Vector2F pos, const char* path, Ids::Ids id) :
    Character(pos, id, path, 7), p2(NULL), bullet(), frameSHOT(0), isEnd(false), score(0) {

}

Entities::Characters::Player::~Player() {
    p2 = NULL;
    bullet = NULL;
}

void Entities::Characters::Player::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM,
    Managers::CollisionManager* CM) {
    frame = 0;
    isJumping = false;
    GM->loadTexture(textPath);
    dimensions = GM->getSize(textPath);
    listenKey = EM->addListenKeyboard([this](const sf::Event e) { handleEvents(e); });

}

void Entities::Characters::Player::update(float t) {
    frameSHOT += t;
    frame += t;
    if (p2) {
        centralizeInView();
    }
    position.x += vel.x * t;
    if (position.x < dimensions.x * 0.5)
        position.x = (float)(dimensions.x * 0.5);
    else if (position.x > (32.0f * 200) - dimensions.x) {
        position.x = (32.0f * 200) - dimensions.x;
        isEnd = true;
    }
    if (!isGround && !isJumping)
        position.y += vel.y * t + GRAVITY;
    else
        position.y += vel.y * t;
}

void Entities::Characters::Player::draw() {
    GM->draw(textPath, position, scale);
}

void Entities::Characters::Player::handleEvents(const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            vel.x = 400;
            scale.x = 1;
            /* code */
            break;
        case sf::Keyboard::Key::A:
            vel.x = -400;
            scale.x = -1;
            /* code */
            break;
        case sf::Keyboard::Key::W:
            if (!isJumping && isGround) {
                vel.y = -900.0f;
                isJumping = true;
                isGround = false;
            }
            break;
        case sf::Keyboard::Key::Space:
            if (frameSHOT > 0.5) {
                createProjectile(position);
                frameSHOT = 0;
            }
        default:
            break;
        }
    }
    if (e.type == sf::Event::KeyReleased) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            vel.x = 0;
            scale.x = 1;
            break;
        case sf::Keyboard::Key::A:
            vel.x = 0;
            scale.x = -1;
            break;
        case sf::Keyboard::Key::W:
            vel.y = 0;
            isJumping = false;
            isGround = false;
            break;
        default:
            break;
        }
    }
}

void Entities::Characters::Player::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    if (idOther == Ids::Player2) {
        if (!isJumping)
            isGround = true;
    }
    else if (idOther == Ids::Homer || idOther == Ids::Ghoul || idOther == Ids::Rock || idOther == Ids::fire) {
        if (frame > 0.4) {
            energy--;
            frame = 0;
        }
        isGround = true;
    }
    else if (idOther == Ids::Nemesis || idOther == Ids::Bone) {
        if (frame > 0.4) {
            energy -= 2;
            frame = 0;
        }
        isGround = true;

    }
    else if (idOther == Ids::ground || idOther == Ids::dirt || idOther == Ids::platform || idOther == Ids::lava) {
        isGround = true;
        float dist_x = (dimensions.x + dimensionsOther.x / 2) -
            std::abs(position.x + dimensions.x / 2 - positionOther.x - dimensionsOther.x / 2);
        float dist_y = (dimensions.y + dimensionsOther.y / 2) -
            std::abs(position.y + dimensions.y / 2 - positionOther.y - dimensionsOther.y / 2);

        if (dist_x * dist_y > .001 * dimensions.x * dimensions.y) {
            if (dist_x < dist_y) {
                if (dist_x > std::abs(adjusts.x)) {
                    if (position.x + dimensions.x / 2 > positionOther.x + dimensionsOther.x / 2) {
                        adjusts.x = dist_x * 1;
                    }
                    else {
                        adjusts.x = dist_x * -1;
                    }
                }
            }
            else {
                if (dist_y > std::abs(adjusts.y)) {
                    if (position.y + dimensions.y / 2 > positionOther.y + dimensionsOther.y / 2) {
                        adjusts.y = dist_y * 1;
                    }
                    else {
                        adjusts.y = dist_y * -1;
                    }
                }
            }
        }
        if (idOther == Ids::lava) {
            if (frame > 0.8) {
                energy -= 2;
                frame = 0;
            }
        }
    }
    else if (idOther == Ids::spiderweb) {
        if (vel.x > 0) vel.x = 100;
        else if (vel.x < 0) vel.x = -100;
    }
    else if (idOther == Ids::empty) {
        isGround = false;
    }
    else {
        isGround = true;
    }
}

void Entities::Characters::Player::createProjectile(Vector2F pos) {
    float v, px;
    bool dir;

    scale.x == 1 ? dir = true : dir = false;

    scale.x == 1 ? v = 800.0f : v = -800.0f;

    scale.x == 1 ? px = 35.0f : px = -35.0f;

    bullet = new Bullet(Vector2F(pos.x + px, pos.y + 20.0f), Vector2F(v, 0.0f), dir);

    EL->insert(bullet);
}


void Entities::Characters::Player::initializeJSON(nlohmann::json j) {
    position = { j["position"] };
    energy = { j["life"] };
    score = { j["Score"] };
}

void Entities::Characters::Player::centralizeInView() {
    if (position.x <= (GM->getCenterView().x) - (GM->getSizeView().x / 2) + dimensions.x / 2)
        position.x = (GM->getCenterView().x) - (GM->getSizeView().x / 2) + dimensions.x / 2;

    else if (position.x >= (GM->getCenterView().x) + (GM->getSizeView().x / 2) - dimensions.x / 2)
        position.x = (GM->getCenterView().x) + (GM->getSizeView().x / 2) - dimensions.x / 2;
}

void Entities::Characters::Player::adjust() {

    if (adjusts.y < 0) {
        isJumping = false;

        vel.y = 0;
    }
    else if (adjusts.y > 0) {
        vel.y = 0;
    }
    Entity::adjust();
}

nlohmann::json Entities::Characters::Player::convertJSON() {
    return {
            { "ID",      ID},
            {"position", position.convertJSON()},
            {"Score",    score},
            {"life",     energy},
            {"Stage",    currentStage}
    };
}


