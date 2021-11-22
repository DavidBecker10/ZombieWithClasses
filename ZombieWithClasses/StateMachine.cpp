#include "StateMachine.h"
#include <iostream>

using namespace States;

StateMachine::~StateMachine() {
    emptyStack();
}

bool StateMachine::execute() {
    return processCode((states.top())->execute());
}

void StateMachine::push(State* s) {
    if (s) states.push(s);
}

void StateMachine::pop() {
    delete states.top();
    states.pop();
}

State* StateMachine::top() {
    return states.top();
}

void StateMachine::emptyStack() {
    while (states.size() != 0) pop();
}
