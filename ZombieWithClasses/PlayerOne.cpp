#include "PlayerOne.h"
#include "stdafx.h"
#include "CollisionManager.h"
#include "Ids.h"

Entities::Characters::PlayerOne::PlayerOne(Vector2F pos, const char* path, Ids::Ids id) :
    Character(pos, Vector2F(0.0f, 0.0f), id, path), bullet(), isLive(true), isEnd(false)
{
}

Entities::Characters::PlayerOne::~PlayerOne() {
}

void Entities::Characters::PlayerOne::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM,
    Managers::CollisionManager* CM) {
    isJumping = false;
    //isGround = false;
    GM->loadTexture(textPath);
    //dimensions = static_cast<sf::Vector2u>(GM->getSize(textPath));
    dimensions = GM->getSize(textPath);
    listenKey = EM->addListenKeyboard([this](const sf::Event e) { handleEvents(e); });
    //CM->addCollide(this);
}

void Entities::Characters::PlayerOne::setTM(Managers::TilesManager* t) {
    TM = t;
}

void Entities::Characters::PlayerOne::update(float t) {
    position.x += vel.x * t;
    if (position.x <= dimensions.x * 0.5)
        position.x = (float)(dimensions.x * 0.5);
    
    else if (position.x >= (32.0f * 200) - dimensions.x) {
        position.x = (32.0f * 200) - dimensions.x;
        isEnd = true;
    }
    
    if (!isGround && !isJumping)
        position.y += vel.y * t + GRAVITY;
    else
        position.y += vel.y * t;
}

void Entities::Characters::PlayerOne::draw() {
    //GM->draw(textPath, position, body, { 1, 9 }, { 0, 5 });
    GM->draw(textPath, position, scale);
    //GM->centralize(position);
}

void Entities::Characters::PlayerOne::handleEvents(const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            vel.x = 300;
            scale.x = 1;
            break;
        case sf::Keyboard::Key::A:
            vel.x = -300;
            scale.x = -1;
            break;
        case sf::Keyboard::Key::W:
            if (!isJumping && isGround) {
                vel.y = -900.0f;
                isJumping = true;
                isGround = false;
            }
            break;
        case sf::Keyboard::Key::Space:
            createProjectile(ID, position, BULLET_PATH);
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

void Entities::Characters::PlayerOne::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    if (idOther != Ids::ground2 && idOther != Ids::Enemy)
        isGround = false;

    switch (idOther) {
    case Ids::Enemy:
        isActive = false;
        break;
    case Ids::Ghoul:
        isActive = false;
        break;
    case Ids::Homer:
        isActive = false;
        break;
    case Ids::Nemesis:
        isActive = false;
        break;
    case Ids::ground2:
        isGround = true;
        if (positionOther.y > position.y)
            vel.y = 0;
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
        isActive = false;
        break;
    case Ids::ground11:
        isGround = true;
        break;
    case Ids::wallL:
        isGround = false;
        break;
    case Ids::Player2:
        if (!isJumping)
            isGround = true;
        break;
    case Ids::spiderweb:
        vel.x *= 0.9;
        isGround = true;    
        break;
    case Ids::ground6:
    default:
        break;
    }
}


void Entities::Characters::PlayerOne::createProjectile(Ids::Ids id, Vector2F pos, const char* path) {
    float v, px;
    bool dir;

    scale.x == 1 ? dir = true : dir = false;

    scale.x == 1 ? v = 900.0f : v = -900.0f;

    scale.x == 1 ? px = 40.0f : px = -40.0f;

    bullet = new Projectile(Vector2F(pos.x + px, pos.y + 18.0f), Vector2F(v, 0.0f), path, dir);

    EL->insert(bullet);
}

void Entities::Characters::PlayerOne::centralizeInView()
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

void Entities::Characters::PlayerOne::initializeJSON(nlohmann::json j) {
    position = { j["position"] };
}
