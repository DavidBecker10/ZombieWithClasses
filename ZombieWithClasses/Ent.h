#pragma once
class Ent
{
protected:
	
	int id;

public:

	Ent(int i = -1);
	~Ent();
	virtual void update(float t) = 0;
	void print();
};