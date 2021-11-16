#include "EventManager.h"

unsigned int Managers::EventManager::proxID{ 0 };

Managers::EventManager::EventManager() {

}

Managers::EventManager::~EventManager() {

}

void Managers::EventManager::manageEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::MouseWheelScrolled
            || event.type == sf::Event::MouseButtonPressed
            || event.type == sf::Event::MouseButtonReleased
            || event.type == sf::Event::MouseMoved) {
            for (auto it : listenMouse) {
                it.second(event);
            }
        }
        else if (event.type == sf::Event::KeyPressed
            || event.type == sf::Event::KeyReleased) {
            for (auto it : listenKeyboard) {
                it.second(event);
            }
        }
        else {
            for (auto it : listenOthers) {
                it.second(event);
            }
        }
    }
}

void Managers::EventManager::setWindow(sf::RenderWindow* w) {
    window = w;

    window->setKeyRepeatEnabled(false);
}

unsigned int Managers::EventManager::addListenMouse(std::function<void(const sf::Event&)> call) {
    listenMouse.emplace(proxID, call);

    return proxID++;
}

void Managers::EventManager::removeListenMouse(int id) {
    listenMouse.erase(id);
}

unsigned int Managers::EventManager::addListenKeyboard(std::function<void(const sf::Event&)> call) {
    listenKeyboard.emplace(proxID, call);

    return proxID++;
}

void Managers::EventManager::removeListenKeyboard(int id) {
    listenKeyboard.erase(id);
}

unsigned int Managers::EventManager::addListenOthers(std::function<void(const sf::Event&)> call)
{
    listenOthers.emplace(proxID, call);

    return proxID++;
}

void Managers::EventManager::removeListenOthers(int id) {
    listenOthers.erase(id);
}