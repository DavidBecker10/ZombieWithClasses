#ifndef ZOMBIEWITHCLASSES_STATEMACHINE_H
#define ZOMBIEWITHCLASSES_STATEMACHINE_H

#include <stack>
#include "State.h"
#include "Ids.h"

namespace States {
    class StateMachine {
    protected:
        std::stack<State*> states;

    public:
        virtual ~StateMachine();
        bool execute();
    protected:
        void push(State* s);
        void pop();
        State* top();
        void emptyStack();
        virtual bool processCode(int returnCode) = 0;
    };
}

#endif //ZOMBIEWITHCLASSES_STATEMACHINE_H
