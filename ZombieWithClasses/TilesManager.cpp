#include "TilesManager.h"
#include <iostream>
#include <cmath>
#include "stdafx.h"

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

void TilesManager::draw(Managers::GraphicManager* g)
{
	for (unsigned int i = 0; i < tileMap.getDimensions().y; i++)
	{
		for (unsigned int j = 0; j < tileMap.getDimensions().x; j++)
		{
			short index = tileMap[i][j] - 1;
			if (index >= 0 && index < (long)tiles.size()) {
				if (((g->getCenterView().y - g->getSizeView().y / 2) - tileDimensions.y < (coordinatesForScreen(sf::Vector2u(j, i))).y) &&
					((g->getCenterView().y + g->getSizeView().y / 2) + tileDimensions.y > (coordinatesForScreen(sf::Vector2u(j, i))).y) &&
					((g->getCenterView().x - g->getSizeView().x / 2) - tileDimensions.x < (coordinatesForScreen(sf::Vector2u(j, i))).x) &&  //Desenha apenas quando estiver dentro da view
					((g->getCenterView().x + g->getSizeView().x / 2) + tileDimensions.x > (coordinatesForScreen(sf::Vector2u(j, i))).x))
				{
					tiles[index]->draw(g, coordinatesForScreen(sf::Vector2u(j, i)));
				}
			}
		}
	}
}

std::vector<TilesManager::infoCollision> TilesManager::checkCollisions(const Ids::Ids id, sf::Vector2f pos, sf::Vector2u s)
{
	
	unsigned int up = (unsigned int) std::floor((pos.y - s.y / 2) / tileDimensions.y);
	unsigned int down = (unsigned int) std::ceil((pos.y + s.y / 2) / tileDimensions.y);
	unsigned int left = (unsigned int) std::floor((pos.x - s.x / 2) / tileDimensions.x);
	unsigned int right = (unsigned int) std::ceil((pos.x + s.x / 2) / tileDimensions.x);

	std::vector<infoCollision> collisions;

	if (up < 0 || left < 0 || down > tileMap.getDimensions().y || right > tileMap.getDimensions().x) return collisions;

	for (unsigned int i = up; i < down; i++)
	{
		for (unsigned int j = left; j < right; j++)
		{
			short index = tileMap[i][j] - 1;
			if (0 <= index && index < (long)tiles.size())
			{
				Entities::Tile* t = tiles[index];
				t->collide(id, pos, s);
				collisions.push_back({ t->getID(), coordinatesForScreen(sf::Vector2u(i, j)), tileDimensions });
			}
		}
	}
	return collisions;
}

sf::Vector2f TilesManager::coordinatesForScreen(const sf::Vector2u pos) const
{
	return sf::Vector2f( tileDimensions.x * 0.5 + tileDimensions.x * pos.x, tileDimensions.y * 1.5f + tileDimensions.y * pos.y );
}

std::vector<Entities::Tile*> TilesManager::getTiles() const
{
	return tiles;
}

void TilesManager::setTile(Entities::Tile* newTile)
{
	if (newTile)
		tiles.push_back(newTile);
	else
		std::cout << "Erro: Elemento nulo em TilesManager::setTile." << std::endl;
}

