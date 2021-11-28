#include "TilesManager.h"
#include <iostream>
#include <cmath>

namespace Managers {

    TilesManager::TilesManager(std::vector<Entities::Tile*> tls, Vector2F tileDim, const char* p) :
        tiles{ tls },
        tileDimensions{ tileDim },
        path{ p },
        tileMap(p) {
        //std::cout << tiles.size() << std::endl;
    }

    TilesManager::~TilesManager() {
        for (Entities::Tile* t : tiles)
            delete t;
    }

    void TilesManager::initialize(Managers::GraphicManager* gm, Managers::EventManager* em, CollisionManager* cm) {
        for (Entities::Tile* t : tiles)
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
                        //std::cout<<"Eu sou macaco velho professor"<<std::endl;
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
                    Entities::Tile* t = tiles[index];
                    t->collide(id, pos, s);
                    collisions.push_back({ t->getID(), coordinatesForScreen(Vector2U(i, j)), tileDimensions });
                }
            }
        }
        return collisions;
    }

    const Vector2F TilesManager::coordinatesForScreen(const Vector2U pos) const {
        //return tileDimensions*(0.5f) + Vector2F(tileDimensions.x * pos.x, tileDimensions.y * pos.y);
        /*return sf::Vector2f{tileDimensions.x * 0.5f + tileDimensions.x * pos.x,
                            tileDimensions.y * 0.5f + tileDimensions.y * pos.y};*/
                            //return tileDimensions.operator*(0.5f) + Vector2F(tileDimensions.x * pos.x, tileDimensions.y * pos.y);
                            //return tileDimensions*0.5f + Vector2F(tileDimensions.x * pos.x, tileDimensions.y * pos.y);
        return Vector2F(tileDimensions.x * 0.5 + tileDimensions.x * pos.x,
            tileDimensions.y * 1.5f + tileDimensions.y * pos.y);
    }

    std::vector<Entities::Tile*> TilesManager::getTiles() const {
        return tiles;
    }

    void TilesManager::setTiles(Entities::Tile* newTile) {
        if (newTile) tiles.push_back(newTile);
        else std::cout << "Erro:TilesManager::setTile." << std::endl;
    }

}