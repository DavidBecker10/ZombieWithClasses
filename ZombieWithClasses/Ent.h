#pragma once
#include "Ids.h"

class Ent
{
protected:
	
	Ids::Ids ID;

public:

	Ent(Ids::Ids id = Ids::empty);
	~Ent();
	virtual void update(float t) = 0;
	void print();
};