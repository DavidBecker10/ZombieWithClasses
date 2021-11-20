#pragma once
#include "State.h"
#include "stdafx.h"

class StateManager
{
private:
	std::stack<State*> stateStack;

public:
	virtual ~StateManager();
	bool execute();
protected:
	void push(State* p);
	void pop();
	void clearStack();
	virtual bool processCode(int code) = 0;
};
