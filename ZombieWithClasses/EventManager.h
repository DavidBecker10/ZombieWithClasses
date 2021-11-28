#ifndef ZOMBIEWITHCLASSES_EVENTMANAGER_H
#define ZOMBIEWITHCLASSES_EVENTMANAGER_H

#include "GraphicManager.h"
#include <map>
#include <functional>
namespace Managers {

    class EventManager {
    private:
        static unsigned int proxID;

        sf::RenderWindow* window;

        std::map<unsigned int, std::function<void(const sf::Event&)>> listenMouse;
        std::map<unsigned int, std::function<void(const sf::Event&)>> listenKeyboard;
        std::map<unsigned int, std::function<void(const sf::Event&)>> listenOthers;

        sf::Event event;
        GraphicManager* GM;

    public:

        EventManager();
        ~EventManager();
        void manageEvent();
        /*void setGraphicManager(GraphicManager* gm);*/
        void setWindow(sf::RenderWindow* w);

        unsigned int addListenMouse(std::function<void(const sf::Event&)> call);
        void removeListenMouse(int id);

        unsigned int addListenKeyboard(std::function<void(const sf::Event&)> call);
        void removeListenKeyboard(int id);

        unsigned int addListenOthers(std::function<void(const sf::Event&)> call);
        void removeListenOthers(int id);
    };
}

#endif //ZOMBIEWITHCLASSES_EVENTMANAGER_H
