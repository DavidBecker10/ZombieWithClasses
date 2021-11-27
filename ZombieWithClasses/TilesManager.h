#ifndef ZOMBIEWITHCLASSES_TILESMANAGER_H
#define ZOMBIEWITHCLASSES_TILESMANAGER_H

#include "TileMap.h"

namespace Managers {

    class TilesManager {
    public:
        typedef struct IdPosSize {
            const Ids::Ids id;
            const Vector2F position;
            const Vector2F size;

        } IdPositionSize;

    private:
        TileMap tileMap;
        Vector2F tileDimensions;
        const char* path;
        std::vector<Entities::Tile*> tiles;

    public:
        TilesManager(std::vector<Entities::Tile*> tls = {}, Vector2F tileDim = { 0.0f, 0.0f }, const char* p = nullptr);

        ~TilesManager();

        void initialize(GraphicManager* gm, EventManager* em, CollisionManager* cm);

        void draw(GraphicManager* g) const;

        std::vector<IdPositionSize> checkCollisions(const Ids::Ids id, Vector2F pos, Vector2F s);

        std::vector<Entities::Tile*> getTiles() const;

        void setTiles(Entities::Tile* newTile);
    private:
        const Vector2F coordinatesForScreen(const Vector2U pos) const;
    };

    using IdPositionSize = TilesManager::IdPositionSize;
}

#endif //ZOMBIEWITHCLASSES_TILESMANAGER_H