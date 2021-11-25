//
// Created by Gabriel on 21/11/2021.
//

#include "Text.h"

Text::Text(Managers::EventManager& em, unsigned short maxL) :
    idListenKeyboard(0), startCapture(false), textDone(false), EM{ em }, maxLenght(maxL) {

}

Text::~Text() {
    EM.removeListenKeyboard(idListenKeyboard);
}

void Text::inicialize() {
    if (startCapture) return;
    startCapture = true;

    text.clear();

    idListenKeyboard = EM.addListenKeyboard([this](const sf::Event& e) {get(e); });
}

void Text::get(const sf::Event& e) {
    if (e.type == sf::Event::EventType::TextEntered) {

        if (text.size() <= maxLenght) {
            char c = (e.text.unicode < 128) ? static_cast<char>(e.text.unicode) : '\0';

            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || c == '_')
                text += c;
        }
    }
    else if (e.type == sf::Event::EventType::KeyReleased) {
        if (e.key.code == sf::Keyboard::Key::Backspace) {
            if (text.size() > 0) text.pop_back();
        }
        else if (e.key.code == sf::Keyboard::Key::Enter) {
            textDone = true;
            startCapture = false;
            EM.removeListenKeyboard(idListenKeyboard);
            idListenKeyboard = 0;
        }
    }
}

