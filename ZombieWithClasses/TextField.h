#pragma once
#include "Button.h"
#include "Text.h"

class TextField :
    public Button
{
private:
    Text txt;

public:
    TextField(Managers::EventManager& em, unsigned short maxL, sf::Vector2f pos = { 0.0f,0.0f }, sf::Vector2f siz = { 0.0f, 0.0f }, unsigned int sText = 15U, sf::Color clr = { 128, 128, 128 });
    ~TextField();
    const std::string& getText() const;
    bool getTextDone() const;
    void draw(Managers::GraphicManager* GM) const override;
    void startCapture();
};