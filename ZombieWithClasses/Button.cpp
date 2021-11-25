//
// Created by Gabriel on 20/11/2021.
//

#include "Button.h"

Button::Button(Vector2F pos, Vector2F siz, std::string txt, std::function<void(void)> press, unsigned int tSize, sf::Color clr1) :
    whenPressed(press), position(pos), size(siz), textSize(tSize), text{ txt }, color{ clr1 } {

}

Button::~Button() {

}

void Button::draw(Managers::GraphicManager& GM) const {
    GM.drawSolidRectangle(position, size, color);
    GM.drawText(text, position, textSize);
}

void Button::press() const {
    whenPressed();
}
