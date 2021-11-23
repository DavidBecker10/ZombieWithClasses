#pragma once
#include "Ids.h"

class Ent
{
protected:
	Ids::Ids ID;
	const char* textPath;

public:

	Ent(Ids::Ids id = Ids::empty, const char* txtPath = nullptr);
	~Ent();
	virtual void update(float t) = 0;
	void print();
	Ids::Ids getID() { return ID; }
	const char* getTextPath() { return textPath; }
};