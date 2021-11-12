#include "EventManager.h"
#include <iostream>

Managers::EventManager::EventManager():
e(),
window(NULL),
close(false)
{
}

Managers::EventManager::~EventManager()
{
    window = NULL;
}

void Managers::EventManager::setWindow(sf::RenderWindow* w)
{
    window = w;
}

bool Managers::EventManager::checkEvent()
{
    if (window)
    {
        if (window->pollEvent(e))
            return true;

        return false;
    }
    else
    {
        std::cerr << "Erro! Ponteiro 'window' nulo em EventManager::checkEvent()." << std::endl;
        exit(1234);
    }
}

void Managers::EventManager::setCharacter(Entities::Characters::Player* p1, Entities::Characters::Player* p2)
{
    pP1 = p1;
    pP2 = p2;
}

bool Managers::EventManager::handleEvent()
{

    if (e.type == sf::Event::Closed)
    {
        window->close();
        close = true;
    }

    if (e.type == sf::Event::KeyPressed || e.type == sf::Event::KeyReleased)
    {
        //Gerencia eventos do Player 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            pP1->moveUp();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            pP1->moveLeft();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            pP1->moveDown();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            pP1->moveRight();

        //Gerencia eventos do Player 2
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            pP2->moveUp();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            pP2->moveLeft();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            pP2->moveDown();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            pP2->moveRight();
        
        close = false;
    }

    return close;
}
