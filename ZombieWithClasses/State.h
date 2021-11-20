#pragma once

class State
{
public:
	virtual ~State();
	virtual int execute() = 0;
};

