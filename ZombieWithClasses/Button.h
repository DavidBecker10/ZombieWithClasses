#pragma once
#include "GraphicManager.h"

#include <functional>

class Button
{
private:
    std::function<void(void)> whenPressed;

protected:
    sf::Vector2f position;
    sf::Vector2f size;
    unsigned int textSize;
    std::string text;
    sf::Color color;

public:
    Button(sf::Vector2f pos = { 0.0f, 0.0f }, sf::Vector2f siz = { 0.0f, 0.0f }, std::string txt = "",
        std::function<void(void)> press = std::function<void(void)>(), unsigned int tSize = 15U, sf::Color clr1 = { 128,128,128 });

    virtual ~Button();

    virtual void draw(Managers::GraphicManager& GM) const;

    sf::Vector2f getPosition() const { return position; }

    sf::Vector2f getSize() const { return size; }

    void press() const;

};

