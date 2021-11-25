//
// Created by Gabriel on 20/11/2021.
//

#ifndef ZOMBIEWITHCLASSES_STATE_H
#define ZOMBIEWITHCLASSES_STATE_H


#include "EventManager.h"
#include "GraphicManager.h"

#include<vector>
#include<iostream>

namespace States {

    class StateMachine;

    class State {
    protected:

    public:
        virtual ~State();
        virtual int execute() = 0;
    };
}


#endif //ZOMBIEWITHCLASSES_STATE_H
