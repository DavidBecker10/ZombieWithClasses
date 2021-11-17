#include "TilesManager.h"
#include <iostream>

TilesManager::TilesManager(std::vector<Tile*> tls, Vector2F tileDim, const char* p):
	tiles(tls),
	tileDimensions(tileDim),
	path(p),
	tileMap(p)
{
}

TilesManager::~TilesManager()
{
	for (Tile* t : tiles)
		delete t;
}

void TilesManager::initialize(Managers::GraphicManager& gm, Managers::EventManager& em)
{
	for (Tile* t : tiles)
		t->initialize(gm);
}

void TilesManager::draw(Managers::GraphicManager& g) const
{
	for (unsigned int i = 0; i < tileDimensions.y; i++)
	{
		for (unsigned int j = 0; j < tileDimensions.x; j++)
		{
			short index = tileMap[i][j] - 1;
			if (index >= 0 && index < (long)tiles.size()) {
				tiles[index]->draw(g, coordinatesForScreen( Vector2U{ j, i} ));
			}
		}
	}
}

std::vector<TilesManager::IdPositionSize> TilesManager::checkCollisions(const Ids::Ids id, Vector2F pos, Vector2F s)
{
	int up = (int) floor((pos.y - s.y / 2) / tileDimensions.y);
	int down = (int) ceil((pos.y + s.y / 2) / tileDimensions.y);
	int left = (int) floor((pos.x - s.x / 2) / tileDimensions.x);
	int right = (int) ceil((pos.x + s.x / 2) / tileDimensions.x);

	std::vector<IdPositionSize> collisions;

	if (up < 0 || left < 0 || down >= (int) tileMap.getDimensions().y || right >= (int)tileMap.getDimensions().x) return collisions;

	for (int i = up; i < down; i++)
	{
		for (int j = left; j < right; j++)
		{
			short index = tileMap[i][j] - 1;
			if (0 <= index && index < (long) tiles.size())
			{
				Tile* t = tiles[index];

				t->collide(id, pos, { (unsigned int)j, (unsigned int)i });
				collisions.push_back({ t->getID(), coordinatesForScreen({(unsigned int)i, (unsigned int)j}), tileDimensions});
			}
		}
	}
	return collisions;
}

const Vector2F TilesManager::coordinatesForScreen(const Vector2U pos) const
{
	//return tileDimensions*(0.5f) + Vector2F(tileDimensions.x * pos.x, tileDimensions.y * pos.y);
	return Vector2F{ tileDimensions.x * 0.5f + tileDimensions.x * pos.x, tileDimensions.y * 0.5f + tileDimensions.y * pos.y };
}

std::vector<Tile*> TilesManager::getTiles() const
{
	return tiles;
}
