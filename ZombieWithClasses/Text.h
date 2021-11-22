#pragma once
#include <string>
#include"EventManager.h"

class Text
{
private:
    std::string text;
    unsigned int idListenKeyboard;
    bool startCapture;
    bool textDone;
    Managers::EventManager& EM;
    unsigned short maxLenght;

public:
    Text(Managers::EventManager& em, unsigned short maxL);
    ~Text();
    void inicialize();
    bool getTextDone() const { return textDone; }
    const std::string& getText() const { return text; }
    void get(const sf::Event& e);
};

