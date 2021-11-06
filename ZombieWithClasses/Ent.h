#pragma once
class Ent
{
protected:
	
	int id;

public:

	Ent(int i = -1);
	~Ent();
	virtual void move(float t) = 0;
	void print();
};