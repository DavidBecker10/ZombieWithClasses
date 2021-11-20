#include "Player.h"
#include "stdafx.h"

Entities::Characters::Player::Player(sf::Vector2f pos, sf::Vector2f vel, Ids::Ids ID, const char* tPath) :
	Character(pos, vel, ID, tPath)
{
}

Entities::Characters::Player::Player() :
	Character()
{
}

Entities::Characters::Player::~Player()
{
}

void Entities::Characters::Player::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM)
{
    isJumping = false;
	GM->loadTexture(textPath);
	dimensions = static_cast<sf::Vector2u>(GM->getSize(textPath));
	listenKey = EM->addListenKeyboard([this](const sf::Event e) {handleEvents(e); });
	CM->addCollide(this);
}

void Entities::Characters::Player::setTM(TilesManager* t)
{
    TM = t;
}

void Entities::Characters::Player::update(float t)
{
    position.x += vel.x * t;
    if (!isJumping && !isGround)
        position.y += vel.y * t + GRAVITY;
    else
        position.y += vel.y * t;
   /* if (position.y < 1455 && !isJumping)
        position.y += vel.y * t + GRAVITY;
    else
        position.y += vel.y * t;*/
}

void Entities::Characters::Player::draw(Managers::GraphicManager* GM)
{
    GM->draw(textPath, position, scale, { 1, 9 }, { 0, 5 });
	GM->centralize(position);
}

void Entities::Characters::Player::handleEvents(const sf::Event& e)
{
    if (e.type == sf::Event::KeyPressed) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            vel.x = 300;
            scale.x = 1;
            /* code */
            break;
        case sf::Keyboard::Key::A:
            vel.x = -300;
            scale.x = -1;
            /* code */
            break;
        case sf::Keyboard::Key::W:
            isJumping = true;
            vel.y = -900;
            isGround = false;
            /* code */
            break;
        case sf::Keyboard::Key::S:
            vel.y = 300;
            /* code */
            break;
        default:
            break;
        }
    }
    else if (e.type == sf::Event::KeyReleased) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            vel.x = 0;
            break;
        case sf::Keyboard::Key::A:
            vel.x = 0;
            break;
        case sf::Keyboard::Key::W:
            vel.y = 0;
            isJumping = false;
            isGround = false;
            break;
        case sf::Keyboard::Key::S:
            vel.y = 0;
            break;
        default:
            break;
        }
    }
}

void Entities::Characters::Player::collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther, bool isAbove)
{
    std::string imprimir;

    if (idOther != Ids::ground2)
        isGround = false;

    switch (idOther) {
    case Ids::Enemy:
        isGround = true;
        break;
    case Ids::ground2:
        if (isAbove)
            isGround = true;
        else {
            isGround = false;
            vel.y *= -1;
        }
        std::cout << isGround << std::endl;
        break;
    case Ids::air:
        isGround = false;
        break;
    case Ids::ground3:
        break;
    case Ids::ground4:
        isGround = true;
        break;
    case Ids::ground5:
        break;
    case Ids::ground8:
        isGround = true;
        break;
    default:
        break;
    }
}

void Entities::Characters::Player::died()
{

}