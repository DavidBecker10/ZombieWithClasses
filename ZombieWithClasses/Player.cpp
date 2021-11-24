#include "Player.h"
#include "stdafx.h"
#include "CollisionManager.h"
#include "Ids.h"

Entities::Characters::Player::Player(Vector2F pos, const char* path) :
    Character(pos, Vector2F(0.0f, 0.0f), Ids::Ids::Player, path) {
}

Entities::Characters::Player::~Player() {
}

void Entities::Characters::Player::initialize(Managers::EventManager* EM,
    Managers::CollisionManager* CM) {
    isJumping = false;
    GM->loadTexture(textPath);
    dimensions = GM->getSize(textPath);
    listenKey = EM->addListenKeyboard([this](const sf::Event e) { handleEvents(e); });
}

void Entities::Characters::Player::setTM(Managers::TilesManager* t) {
    TM = t;
}

void Entities::Characters::Player::update(float t) {
    position.x += vel.x * t;
    if (position.x <= dimensions.x * 0.5)
        position.x = (float)(dimensions.x * 0.5);
    else if (position.x >= (32.0f * 200) - dimensions.x)
        position.x = (32.0f * 200) - dimensions.x;
    if (!isGround && !isJumping)
        position.y += vel.y * t + GRAVITY;
    else
        position.y += vel.y * t;
}

void Entities::Characters::Player::draw() {
    GM->draw(textPath, position, scale);
    GM->centralize(position);
}

void Entities::Characters::Player::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    if (idOther != Ids::ground2 && idOther != Ids::Enemy)
        isGround = false;

    switch (idOther) {
    case Ids::Enemy:
        EL->remove(this);
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
        break;
    case Ids::ground11:
        isGround = true;
        break;
    case Ids::wallL:
        isGround = false;
        break;
    default:
        break;
    }
}


void Entities::Characters::Player::createProjectile(Ids::Ids id, Vector2F pos, const char* path) {
    float v, px;
    bool dir;

    scale.x == 1 ? dir = true : dir = false;

    scale.x == 1 ? v = 900.0f : v = -900.0f;

    scale.x == 1 ? px = 35.0f : px = -35.0f;

    EL->insert(new Projectile(Vector2F(pos.x + px, pos.y + 20.0f), Vector2F(v, 0.0f), path, dir));
}

void Entities::Characters::Player::neutralized() {

}