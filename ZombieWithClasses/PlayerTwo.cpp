#include "PlayerTwo.h"
#include "stdafx.h"
#include "CollisionManager.h"
#include "Ids.h"

Entities::Characters::PlayerTwo::PlayerTwo(Vector2F pos) :
    Character(pos, Vector2F(0.0f, 0.0f), Ids::Ids::Player2, PLAYER2_PATH), bullet(), isLive(true), isEnd(false) {
}

Entities::Characters::PlayerTwo::~PlayerTwo() {
}

void Entities::Characters::PlayerTwo::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM,
    Managers::CollisionManager* CM) {
    isJumping = false;
    //isGround = false;
    GM->loadTexture(textPath);
    //dimensions = static_cast<sf::Vector2u>(GM->getSize(textPath));
    dimensions = GM->getSize(textPath);
    listenKey = EM->addListenKeyboard([this](const sf::Event e) { handleEvents(e); });
    //CM->addCollide(this);

}

void Entities::Characters::PlayerTwo::setTM(Managers::TilesManager* t) {
    TM = t;
}

void Entities::Characters::PlayerTwo::update(float t) {
    position.x += vel.x * t;
    if (position.x <= dimensions.x * 0.5)
        position.x = (float)(dimensions.x * 0.5);
    else if (position.x >= (32.0f * 200) - dimensions.x)
        position.x = (32.0f * 200) - dimensions.x;

    if (position.x <= (GM->getCenterView().x) - (GM->getSizeView().x / 2) + dimensions.x / 2)
        position.x = (GM->getCenterView().x) - (GM->getSizeView().x / 2) + dimensions.x / 2;

    else if (position.x >= (GM->getCenterView().x) + (GM->getSizeView().x / 2) - dimensions.x / 2)
        position.x = (GM->getCenterView().x) + (GM->getSizeView().x / 2) - dimensions.x / 2;

    if (position.y <= (GM->getCenterView().y) - (GM->getSizeView().y / 2) - dimensions.y / 2)
        position.y = (GM->getCenterView().y) - (GM->getSizeView().y / 2 - dimensions.y / 2);

    else if (position.y >= (GM->getCenterView().y) + (GM->getSizeView().y / 2) + dimensions.y / 2)
        position.y = (GM->getCenterView().y) + (GM->getSizeView().y / 2 + dimensions.y / 2);

    if (!isGround && !isJumping)
        position.y += vel.y * t + GRAVITY;
    else
        position.y += vel.y * t;
}

void Entities::Characters::PlayerTwo::draw() {
    //GM->draw(textPath, position, body, { 1, 9 }, { 0, 5 });
    GM->draw(textPath, position, scale);
    //GM->centralize(position);
}

void Entities::Characters::PlayerTwo::handleEvents(const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        switch (e.key.code) {
        case sf::Keyboard::Key::Right:
            vel.x = 300;
            scale.x = 1;
            /* code */
            break;
        case sf::Keyboard::Key::Left:
            vel.x = -300;
            scale.x = -1;
            /* code */
            break;
        case sf::Keyboard::Key::Up:
            if (!isJumping && isGround) {
                vel.y = -900.0f;
                isJumping = true;
                isGround = false;
            }
            /* code */
            break;
        case sf::Keyboard::Key::Enter:
            createProjectile(ID, position, BULLET_PATH);
        default:
            break;
        }
    }
    if (e.type == sf::Event::KeyReleased) {
        switch (e.key.code) {
        case sf::Keyboard::Key::Right:
            vel.x = 0;
            scale.x = 1;
            /* code */
            break;
        case sf::Keyboard::Key::Left:
            vel.x = 0;
            scale.x = -1;
            /* code */
            break;
        case sf::Keyboard::Key::Up:
            vel.y = 0;
            isJumping = false;
            isGround = false;

            /* code */
            break;
            //            case sf::Keyboard::Key::Space:
            //                createProjectile(ID, position, BULLET_PATH);
        default:
            break;
        }
    }
}

void Entities::Characters::PlayerTwo::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    if (idOther != Ids::ground2 && idOther != Ids::Enemy)
        isGround = false;

    switch (idOther) {
    case Ids::Enemy:
        EL->remove(this);
        isLive = false;
        break;
    case Ids::Ghoul:
        EL->remove(this);
        isLive = false;
        break;
    case Ids::Homer:
        EL->remove(this);
        isLive = false;
        break;
    case Ids::Nemesis:
        EL->remove(this);
        isLive = false;
        break;
    case Ids::ground2:
        isGround = true;
        if (positionOther.y > position.y)
            vel.y = 0;
        //std::cout << isGround << std::endl;
        break;
    case Ids::air:
        vel.y = 0;
        isGround = false;
        isJumping = true;
        break;
    case Ids::wallR:
        isGround = true;
        break;
    case Ids::Projectile:
        isGround = true;
        break;
    case Ids::lava:
        EL->remove(this);
        isLive = false;
        break;
    case Ids::ground11:
        isGround = true;
        break;
    case Ids::wallL:
        isGround = false;
        break;
    case Ids::Player1:
        if(!isJumping)
            isGround = true;
        break;
    default:
        break;
    }
}


void Entities::Characters::PlayerTwo::createProjectile(Ids::Ids id, Vector2F pos, const char* path) {
    float v, px;
    bool dir;

    scale.x == 1 ? dir = true : dir = false;

    scale.x == 1 ? v = 900.0f : v = -900.0f;

    scale.x == 1 ? px = 20.0f : px = -20.0f;

    bullet = new Projectile(Vector2F(pos.x + px, pos.y + 30.0f), Vector2F(v, 0.0f), path, dir);

    EL->insert(bullet);
}

void Entities::Characters::PlayerTwo::centralizeInView()
{
    if (position.x <= (GM->getCenterView().x) - (GM->getSizeView().x / 2) + dimensions.x / 2)
        position.x = (GM->getCenterView().x) - (GM->getSizeView().x / 2) + dimensions.x / 2;

    else if (position.x >= (GM->getCenterView().x) + (GM->getSizeView().x / 2) - dimensions.x / 2)
        position.x = (GM->getCenterView().x) + (GM->getSizeView().x / 2) - dimensions.x / 2;

    if (position.y <= (GM->getCenterView().y) - (GM->getSizeView().y / 2) - dimensions.y / 2)
        position.y = (GM->getCenterView().y) - (GM->getSizeView().y / 2 - dimensions.y / 2);

    else if (position.y >= (GM->getCenterView().y) + (GM->getSizeView().y / 2) + dimensions.y / 2)
        position.y = (GM->getCenterView().y) + (GM->getSizeView().y / 2 + dimensions.y / 2);
}

void Entities::Characters::PlayerTwo::initializeJSON(nlohmann::json j) {
    position = { j["position"] };
}
