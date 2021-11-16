#pragma once
#include "Vector2D.h"
#include "TileMap.h"
#include "Tile.h"
#include "GraphicManager.h"
#include "EventManager.h"
#include "CollisionManager.h"
#include "Ids.h"
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
	std::vector<Tile*> tiles;

public:
	TilesManager(std::vector<Tile*> tls, Vector2F tileDim, const char* p);
	~TilesManager();
	void initialize(Managers::GraphicManager& gm, Managers::EventManager& em);
	void draw(Managers::GraphicManager& g) const;
	std::vector<IdPositionSize> checkCollisions(const Ids::Ids id, Vector2F pos, Vector2F s);
	const Vector2F coordinatesForScreen(const Vector2U pos) const;
	std::vector<Tile*> getTiles() const;
};

