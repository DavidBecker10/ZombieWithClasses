#include "Button.h"

Button::Button(sf::Vector2f pos, sf::Vector2f siz, std::string txt, std::function<void(void)> press, unsigned int tSize, sf::Color clr1) :
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
