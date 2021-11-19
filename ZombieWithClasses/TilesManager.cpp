#include "TilesManager.h"
#include <iostream>
#include <cmath>

TilesManager::TilesManager(std::vector<Entities::Tile*> tls, sf::Vector2f tileDim, const char* p):
	tiles(tls),
	tileDimensions(tileDim),
	path(p),
	tileMap(p)
{
}

TilesManager::~TilesManager()
{
	for (Entities::Tile* t : tiles)
		delete t;
}

void TilesManager::initialize(Managers::GraphicManager* gm, Managers::EventManager* em, CollisionManager* cm)
{
	for (Entities::Tile* t : tiles)
		t->initialize(gm, em, cm);
}

void TilesManager::draw(Managers::GraphicManager& g)
{
	for (unsigned int i = 0; i < tileMap.getDimensions().y; i++)
	{
		for (unsigned int j = 0; j < tileMap.getDimensions().y; j++)
		{
			short index = tileMap[i][j] - 1;
			if (index >= 0 && index < (long)tiles.size()) {
				tiles[index]->draw(g, coordinatesForScreen(sf::Vector2u{ j, i} ));
			}
		}
	}
}

std::vector<TilesManager::IdPositionSize> TilesManager::checkCollisions(const Ids::Ids id, sf::Vector2f pos, sf::Vector2f s)
{
	int up = (int) std::floor((pos.y - s.y / 2) / tileMap.getDimensions().y);
	int down = (int) std::ceil((pos.y + s.y / 2) / tileMap.getDimensions().y);
	int left = (int) std::floor((pos.x - s.x / 2) / tileMap.getDimensions().x);
	int right = (int) std::ceil((pos.x + s.x / 2) / tileMap.getDimensions().x);

	std::vector<IdPositionSize> collisions;

	if (up < 0 || left < 0 || down >= (int) tileMap.getDimensions().y || right >= (int)tileMap.getDimensions().x) return collisions;

	for (int i = up; i < down; i++)
	{
		for (int j = left; j < right; j++)
		{
			short index = tileMap[i][j] - 1;
			if (0 <= index && index < (long) tiles.size())
			{
				Entities::Tile* t = tiles[index];
				std::cout << index << std::endl;
				t->collide(id, pos, {(float)j, (float)i });
				collisions.push_back({ t->getID(), coordinatesForScreen({(unsigned int)i, (unsigned int)j}), tileDimensions});
			}
		}
	}
	return collisions;
}

sf::Vector2f TilesManager::coordinatesForScreen(const sf::Vector2u pos) const
{
	//return tileDimensions*(0.5f) + Vector2F(tileDimensions.x * pos.x, tileDimensions.y * pos.y);
	return sf::Vector2f{ tileDimensions.x * 0.5f + tileDimensions.x * pos.x, tileDimensions.y * 0.5f + tileDimensions.y * pos.y };
}

std::vector<Entities::Tile*> TilesManager::getTiles() const
{
	return tiles;
}

void TilesManager::setTiles(std::vector<Entities::Tile*> newTile)
{

}

