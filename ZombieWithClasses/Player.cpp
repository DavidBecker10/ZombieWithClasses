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

void Entities::Characters::Player::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM)
{
    printf("oi");
	GM->loadTexture(textPath);
	dimensions = GM->getSize(textPath);
	listenKey = EM->addListenKeyboard([this](const sf::Event e) {handleEvents(e); });
	//CM.addCollide(this);
}

void Entities::Characters::Player::update(float t)
{
	
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
            position.x += 30;
            /* code */
            break;
        case sf::Keyboard::Key::A:
            position.x -= 30;
            /* code */
            break;
        case sf::Keyboard::Key::W:
            position.y -= 30;
            /* code */
            break;
        case sf::Keyboard::Key::S:
            position.y += 30;
            /* code */
            break;
        default:
            break;
        }
    }
    else if (e.type == sf::Event::KeyReleased) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            position.x += 30;
            break;
        case sf::Keyboard::Key::A:
            position.x -= 30;
            break;
        case sf::Keyboard::Key::W:
            position.y -= 30;
            break;
        case sf::Keyboard::Key::S:
            position.y += 30;
            break;
        default:
            break;
        }
    }
}

void Entities::Characters::Player::collide(Ids::Ids idOutro, Vector2F posicaoOutro, Vector2F dimensoesOutro)
{
    std::string imprimir;

    switch (idOutro) {
    case Ids::Player:
        imprimir = "ai ui ui";
        break;
    case Ids::ground1:
        imprimir = "fui ludibriado";
        break;
    case Ids::ground2:
        imprimir = "cai";
        break;
    case Ids::empty:
        imprimir = "mano o que ta acontecendo";
        break;
    case Ids::ground3:
        imprimir = "pontudo";
        break;
    case Ids::ground4:
        imprimir = "estou livre";
        break;
    case Ids::ground5:
        imprimir = "bonk";
        break;
    default:
        break;
    }

    std::cout << imprimir << std::endl;
}
