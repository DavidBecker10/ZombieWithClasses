#ifndef ZOMBIEWITHCLASSES_MENU_H
#define ZOMBIEWITHCLASSES_MENU_H

#include "State.h"

#include "ButtonManager.h"
namespace States {
    class Menu : public State {
    private:
        int returnCode;

    protected:
        Managers::GraphicManager* GM;
        Managers::EventManager EM;
        Managers::ButtonManager BM;

    public:
        Menu(Managers::GraphicManager& gm);
        virtual ~Menu();
        virtual int execute() override;
        int getReturnCode() const { return returnCode; }

    protected:
        void setReturnCode(int rc) { returnCode = rc; };
    };
}
#endif //ZOMBIEWITHCLASSES_MENU_H
