#pragma once
#include "Vector2D.h"
#include "GraphicManager.h"

class Tile
{
private:
	const Ids id;
	const char* path;
	Vector2F size;
	Managers::GraphicManager& GM;

public:
	Tile(const Ids::Ids i, const char* p, Vector2F s);
	~Tile();
	virtual void initialize(Managers::GraphicManager& g);
	void draw() const;
	const Ids::Ids getID() const;
	virtual void collide(Ids::Ids idOther, Vector2F posOther, Vector2U pos);
};

