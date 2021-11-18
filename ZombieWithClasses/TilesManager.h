#pragma once
#include "Vector2D.h"
#include "TileMap.h"
#include "Tile.h"
#include "GraphicManager.h"
#include "EventManager.h"
#include "CollisionManager.h"
#include "Ids.h"

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
	std::vector<Entities::Tile*> tiles;

public:
	TilesManager(std::vector<Entities::Tile*> tls, Vector2F tileDim, const char* p);
	~TilesManager();
	void initialize(Managers::GraphicManager* gm, Managers::EventManager* em, CollisionManager* cm);
	void draw(Managers::GraphicManager& g);
	std::vector<IdPositionSize> checkCollisions(const Ids::Ids id, Vector2F pos, Vector2F s);
	Vector2F coordinatesForScreen(const Vector2U pos) const;
	std::vector<Entities::Tile*> getTiles() const;
	void setTiles(std::vector<Entities::Tile*>);
	//std::vector<IdPositionSize> checkMapCollisions(const Ids::Ids id, Vector2F pos, Vector2F s);
};

