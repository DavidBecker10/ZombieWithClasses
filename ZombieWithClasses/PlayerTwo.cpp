#include "PlayerTwo.h"
#include "PlayerOne.h"
#include "Entity.h"
#include "stdafx.h"
#include "CollisionManager.h"
#include "Ids.h"

Entities::Characters::PlayerTwo::PlayerTwo(Vector2F pos) :
    PlayerOne(pos, PLAYER2_PATH, Ids::Ids::Player2){
}

Entities::Characters::PlayerTwo::~PlayerTwo() {
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