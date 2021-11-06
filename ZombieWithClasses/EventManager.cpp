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
//a
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

bool Managers::EventManager::handleEvent()
{
    if (e.type == sf::Event::Closed)
    {
        window->close();
        close = true;
    }

    /*Implementar demais eventos*/

    return close;
}
