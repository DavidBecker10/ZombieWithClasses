#pragma once
#include "EventManager.h"
#include "Button.h"
#include "stdafx.h"

namespace Managers
{
	class ButtonManager
	{
    private:
        std::vector<Button*> buttons;
        EventManager* EM;
        GraphicManager* GM;
        unsigned int idListenMouse;

    public:
        ButtonManager(EventManager* em, GraphicManager* gm, std::vector<Button*> b = {});
        ~ButtonManager();
        void draw() const;
        void listenMouse(const sf::Event& e);
        void addButton(Button* b);
	};
}
