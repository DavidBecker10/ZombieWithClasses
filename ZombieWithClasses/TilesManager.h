#pragma once
#include "Vector2D.h"
#include "TileMap.h"
#include "Tile.h"
#include "GraphicManager.h"
#include "EventManager.h"
#include "CollisionManager.h"
#include <vector>

class TilesManager
{
public:
	typedef struct IdPosSize
	{
		const Ids::Ids id;
		const Vector2F position;
		const Vector2F size;

	}IdPositionSize;

private:
	TileMap tileMap;
	Vector2F tileDimensions;
	const char* path;
	std::vector<Tile> tiles;

public:
	TilesManager(std::vector<Tile> tls, Vector2F tileDim, const char* p);
	~TilesManager();
	void update(float t);
	void initialize(Managers::GraphicManager& gm, Managers::EventManager& em, Managers::CollisionManager& cm);
	void draw(Managers::GraphicManager& g) const;
	void checkCollisions(const Ids::Ids id, Vector2F pos, Vector2F s);
};

