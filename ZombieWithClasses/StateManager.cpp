#include "StateManager.h"


StateManager::~StateManager() {
    clearStack();
}

bool StateManager::execute() {
    // Estado* estado = pilhaEstados.top();
    // int codigoRetorno = estado->executar();
    // bool terminar = processarCodigo(codigoRetorno);
    // return terminar;

    return processCode((stateStack.top())->execute());
}

void StateManager::push(State* p) {
    if (p) stateStack.push(p);
}

void StateManager::pop() {
    delete stateStack.top();
    stateStack.pop();
}

void StateManager::clearStack() {
    while (stateStack.size() != 0)
        pop();
}