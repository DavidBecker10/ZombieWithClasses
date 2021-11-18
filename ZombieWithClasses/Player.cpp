#include "Player.h"
#include <iostream>

Entities::Characters::Player::Player(Vector2F pos, Vector2F vel, Ids::Ids ID, const char* tPath) :
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
    //printf("aaaa");
	GM->loadTexture(textPath);
	dimensions = GM->getSize(textPath);
	listenKey = EM->addListenKeyboard([this](const sf::Event e) {handleEvents(e); });
	CM->addCollide(this);
}

void Entities::Characters::Player::setTM(TilesManager* t)
{
    TM = t;
}

void Entities::Characters::Player::update(float t)
{
    position = vel * t;
}

void Entities::Characters::Player::draw(Managers::GraphicManager* GM)
{
    GM->draw(textPath, position, { 1, 9 }, { 0, 5 });
	GM->centralize(position);
}

void Entities::Characters::Player::handleEvents(const sf::Event& e)
{
    if (e.type == sf::Event::KeyPressed) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            vel.x += 30;
            /* code */
            break;
        case sf::Keyboard::Key::A:
            vel.x -= 30;
            /* code */
            break;
        case sf::Keyboard::Key::W:
            vel.y -= 30;
            /* code */
            break;
        case sf::Keyboard::Key::S:
            vel.y += 30;
            /* code */
            break;
        default:
            break;
        }
    }
    else if (e.type == sf::Event::KeyReleased) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            vel.x += 30;
            break;
        case sf::Keyboard::Key::A:
            vel.x -= 30;
            break;
        case sf::Keyboard::Key::W:
            vel.y -= 30;
            break;
        case sf::Keyboard::Key::S:
            vel.y += 30;
            break;
        default:
            break;
        }
    }
}

void Entities::Characters::Player::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther)
{
    //std::cout << idOther << '    ' /*<< idOther*/ << std::endl;
    std::string imprimir;

    switch (idOther) {
    case Ids::Enemy:
        imprimir = "Zombie pnc";
        std::cout << imprimir << std::endl;
        break;
    case Ids::ground1:
        imprimir = "fui ludibriado";
        std::cout << imprimir << std::endl;
        break;
    case Ids::ground2:
        imprimir = "cai";
        std::cout << imprimir << std::endl;
        break;
    case Ids::empty:
        imprimir = "mano o que ta acontecendo";
        std::cout << imprimir << std::endl;
        break;
    case Ids::ground3:
        imprimir = "pontudo";
        std::cout << imprimir << std::endl;
        break;
    case Ids::ground4:
        imprimir = "estou livre";
        std::cout << imprimir << std::endl;
        break;
    case Ids::ground5:
        imprimir = "bonk";
        std::cout << imprimir << std::endl;
        break;
    default:
        break;
    }
}
