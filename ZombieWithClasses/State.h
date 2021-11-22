#pragma once
#include "EventManager.h"
#include "GraphicManager.h"
#include "stdafx.h"

namespace States {

    class StateMachine;

    class State {
    protected:

    public:
        virtual ~State();
        virtual int execute() = 0;
    };
}
