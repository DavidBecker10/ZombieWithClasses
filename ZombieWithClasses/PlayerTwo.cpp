#include "PlayerTwo.h"
#include "stdafx.h"

Entities::Characters::PlayerTwo::PlayerTwo(Vector2F pos) :
    Player(pos, PLAYER2_PATH, Ids::Ids::Player2) {

}

Entities::Characters::PlayerTwo::~PlayerTwo() {

}

void Entities::Characters::PlayerTwo::handleEvents(const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        switch (e.key.code) {
        case sf::Keyboard::Key::Right:
            vel.x = 400;
            scale.x = 1;
            break;
        case sf::Keyboard::Key::Left:
            vel.x = -400;
            scale.x = -1;
            break;
        case sf::Keyboard::Key::Up:
            if (!isJumping && isGround) {
                vel.y = -900.0f;
                isJumping = true;
                isGround = false;
            }
            break;
        case sf::Keyboard::Key::Enter:
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
        case sf::Keyboard::Key::Right:
            vel.x = 0;
            scale.x = 1;
            break;
        case sf::Keyboard::Key::Left:
            vel.x = 0;
            scale.x = -1;
            break;
        case sf::Keyboard::Key::Up:
            vel.y = 0;
            isJumping = false;
            isGround = false;

            break;
        default:
            break;
        }
    }
}

void Entities::Characters::PlayerTwo::centralizeInView() {
    if (position.x <= (GM->getCenterView().x) - (GM->getSizeView().x / 2) + dimensions.x / 2)
        position.x = (GM->getCenterView().x) - (GM->getSizeView().x / 2) + dimensions.x / 2;

    else if (position.x >= (GM->getCenterView().x) + (GM->getSizeView().x / 2) - dimensions.x / 2)
        position.x = (GM->getCenterView().x) + (GM->getSizeView().x / 2) - dimensions.x / 2;

    if (position.y <= (GM->getCenterView().y) - (GM->getSizeView().y / 2) - dimensions.y / 2)
        position.y = (GM->getCenterView().y) - (GM->getSizeView().y / 2 - dimensions.y / 2);

    else if (position.y >= (GM->getCenterView().y) + (GM->getSizeView().y / 2) + dimensions.y / 2)
        position.y = (GM->getCenterView().y) + (GM->getSizeView().y / 2 + dimensions.y / 2);
}