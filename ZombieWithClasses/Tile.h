#pragma once
#include "Vector2D.h"
#include "GraphicManager.h"
#include "Ids.h"

class Tile
{
private:
	const Ids::Ids id;
	const char* path;
	Vector2F size;
	Managers::GraphicManager* GM;

public:
	Tile(const Ids::Ids i, const char* p, Vector2F s);
	Tile();
	~Tile();
	virtual void initialize(Managers::GraphicManager& g);
	void draw(Managers::GraphicManager& g, const Vector2F position) const;
	const Ids::Ids getID() const;
	virtual void collide(Ids::Ids idOther, Vector2F posOther, Vector2U pos);
};

