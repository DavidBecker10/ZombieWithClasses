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
	typedef struct infoCollision
	{
		const Ids::Ids id;
		const sf::Vector2f position;
		const sf::Vector2u size;

	}infoCollision;

private:
	TileMap tileMap;
	sf::Vector2u tileDimensions;
	const char* path;
	std::vector<Entities::Tile*> tiles;

public:
	TilesManager(std::vector<Entities::Tile*> tls, sf::Vector2f tileDim, const char* p);
	~TilesManager();
	void initialize(Managers::GraphicManager* gm, Managers::EventManager* em, CollisionManager* cm);
	void draw(Managers::GraphicManager* g);
	std::vector<infoCollision> checkCollisions(const Ids::Ids id, sf::Vector2f pos, sf::Vector2u s);
	sf::Vector2f coordinatesForScreen(const sf::Vector2u pos) const;
	std::vector<Entities::Tile*> getTiles() const;
	void setTile(Entities::Tile* newTile);
};

