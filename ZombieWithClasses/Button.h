//
// Created by Gabriel on 20/11/2021.
//

#ifndef ZOMBIEWITHCLASSES_BUTTON_H
#define ZOMBIEWITHCLASSES_BUTTON_H

#include "GraphicManager.h"

#include <functional>


class Button {
private:
    std::function<void(void)> whenPressed;

protected:
    Vector2F position;
    Vector2F size;
    unsigned int textSize;
    std::string text;
    sf::Color color;

public:
    Button(Vector2F pos = { 0.0f, 0.0f }, Vector2F siz = { 0.0f, 0.0f }, std::string txt = "",
        std::function<void(void)> press = std::function<void(void)>(), unsigned int tSize = 15U, sf::Color clr1 = { 128,128,128 });

    virtual ~Button();

    virtual void draw(Managers::GraphicManager& GM) const;

    Vector2F getPosition() const { return position; }

    Vector2F getSize() const { return size; }

    void press() const;

    void setColor(sf::Color clr) { color = clr; }
 
    };


#endif //ZOMBIEWITHCLASSES_BUTTON_H
