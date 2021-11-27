#include "TextField.h"

TextField::TextField(Managers::EventManager& em, unsigned short maxL, Vector2F pos, Vector2F siz, unsigned int sText,
    sf::Color clr) :
    Button{ pos, siz, "", [this]() {startCapture(); }, sText, clr }, txt{ em, maxL }
{

}

TextField::~TextField() {

}

const std::string& TextField::getText() const {
    if (!getTextDone()) throw "Error! Verify getTextDone() before calling this method";
    return txt.getText();
}

bool TextField::getTextDone() const {
    return txt.getTextDone();
}

void TextField::draw(Managers::GraphicManager& GM) const {
    GM.drawSolidRectangle(position, size, color);
    GM.drawText(txt.getText(), position, textSize, false);
}

void TextField::startCapture() {
    txt.inicialize();
}
