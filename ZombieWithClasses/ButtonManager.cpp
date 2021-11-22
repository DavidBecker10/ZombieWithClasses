#include "ButtonManager.h"

using namespace Managers;

ButtonManager::ButtonManager(EventManager* em, GraphicManager* gm, std::vector<Button*> b) :
    buttons{ b }, EM{ em }, GM{ gm } {
    idListenMouse = EM->addListenMouse([this](const sf::Event& e) {listenMouse(e); });
}

ButtonManager::~ButtonManager() {
    EM->removeListenMouse(idListenMouse);
}

void ButtonManager::draw() const {
    for (Button* b : buttons) b->draw(GM);
}

void ButtonManager::listenMouse(const sf::Event& e) {
    if (e.type == sf::Event::MouseButtonReleased) {

        sf::Vector2f mousePos = GM->getMousePosition();

        for (Button* b : buttons) {
            sf::Vector2f posButtonCenter = b->getPosition();
            sf::Vector2f buttonSize = b->getSize();
            sf::Vector2f distanceMouseCenter = mousePos - posButtonCenter;
            if (fabs(distanceMouseCenter.x) < buttonSize.x / 2 && fabs(distanceMouseCenter.y) < buttonSize.y / 2) b->press();
        }

    }
}

void ButtonManager::addButton(Button* b) {
    if (b) buttons.push_back(b);
}
