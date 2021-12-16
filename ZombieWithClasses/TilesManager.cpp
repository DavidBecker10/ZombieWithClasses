#include "TilesManager.h"
#include <iostream>
#include <cmath>

namespace Managers {

    TilesManager::TilesManager(std::vector<Tiles::Tile*> tls, Vector2F tileDim, const char* p) :
        tiles{ tls },
        tileDimensions{ tileDim },
        path{ p },
        tileMap(p) {
    }

    TilesManager::~TilesManager() {
        for (Tiles::Tile* t : tiles)
            delete t;
    }

    void TilesManager::initialize(Managers::GraphicManager* gm, Managers::EventManager* em, CollisionManager* cm) {
        for (Tiles::Tile* t : tiles)
            t->initialize(gm, em, cm);
    }

    void TilesManager::draw(Managers::GraphicManager* g) const {
        for (unsigned int i = 0; i < tileMap.getDimensions().y; i++) {
            for (unsigned int j = 0; j < tileMap.getDimensions().x; j++) {
                short index = tileMap[i][j] - 1;
                if (index >= 0 && index < (long)tiles.size()) {
                    if (((g->getCenterView().y - g->getSizeView().y / 2) - tileDimensions.y <
                        (coordinatesForScreen(Vector2U(j, i))).y) &&
                        ((g->getCenterView().y + g->getSizeView().y / 2) + tileDimensions.y >
                            (coordinatesForScreen(Vector2U(j, i))).y) &&
                        ((g->getCenterView().x - g->getSizeView().x / 2) - tileDimensions.x <
                            (coordinatesForScreen(Vector2U(j, i))).x) &&//Desenha apenas quando estiver dentro da view
                        ((g->getCenterView().x + g->getSizeView().x / 2) + tileDimensions.x >
                            (coordinatesForScreen(Vector2U(j, i))).x)) {
                        tiles[index]->draw(coordinatesForScreen(Vector2U(j, i)));
                    }
                }
            }
        }
    }

    std::vector<TilesManager::IdPositionSize>
        TilesManager::checkCollisions(const Ids::Ids id, Vector2F pos, Vector2F s) {
        unsigned int up = (unsigned int)std::floor((pos.y - s.y / 2) / tileDimensions.y);
        unsigned int down = (unsigned int)std::ceil((pos.y + s.y / 2) / tileDimensions.y);
        unsigned int left = (unsigned int)std::floor((pos.x - s.x / 2) / tileDimensions.x);
        unsigned int right = (unsigned int)std::ceil((pos.x + s.x / 2) / tileDimensions.x);

        std::vector<IdPositionSize> collisions;

        if (up < 0 || left < 0 || down > tileMap.getDimensions().y || right > tileMap.getDimensions().x)
            return collisions;

        for (unsigned int i = up; i < down; i++) {
            for (unsigned int j = left; j < right; j++) {
                short index = tileMap[i][j] - 1;
                if (0 <= index && index < (long)tiles.size()) {
                    Tiles::Tile* t = tiles[index];
                    t->collide(id, pos, s);
                    collisions.push_back({ t->getID(), coordinatesForScreen(Vector2U(i, j)), tileDimensions });
                }
            }
        }
        return collisions;
    }

    const Vector2F TilesManager::coordinatesForScreen(const Vector2U pos) const {
        return Vector2F(tileDimensions.x * 0.5 + tileDimensions.x * pos.x,
            tileDimensions.y * 1.5f + tileDimensions.y * pos.y);
    }

    std::vector<Tiles::Tile*> TilesManager::getTiles() const {
        return tiles;
    }

    void TilesManager::setTiles(Tiles::Tile* newTile) {
        if (newTile) tiles.push_back(newTile);
        else std::cout << "Erro:TilesManager::setTile." << std::endl;
    }

    void TilesManager::regenTiles() {
        tileMap.loadMap();
        for (unsigned i = 0; i < tileMap.getDimensions().y; ++i) {
            for (unsigned j = 0; j < tileMap.getDimensions().x; ++j) {

                if (tileMap[i][j] == 9) webSpawn = Vector2U(j, i - 1);
                if (tileMap[i][j] == 10) fireSpawn = Vector2U(j, i);

            }
        }
    }

}