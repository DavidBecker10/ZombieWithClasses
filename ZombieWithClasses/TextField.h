#ifndef ZOMBIEWITHCLASSES_TEXTFIELD_H
#define ZOMBIEWITHCLASSES_TEXTFIELD_H

#include"Button.h"
#include "Text.h"
class TextField :public Button {
private:
    Text txt;
public:
    TextField(Managers::EventManager* em, unsigned short maxL, Vector2F pos = { 0.0f,0.0f }, Vector2F siz = { 0.0f, 0.0f }, unsigned int sText = 15U, sf::Color clr = { 128, 128, 128 });
    ~TextField();
    const std::string& getText() const;
    bool getTextDone() const;
    void draw(Managers::GraphicManager& GM) const override;
    void startCapture();
};


#endif //ZOMBIEWITHCLASSES_TEXTFIELD_H
