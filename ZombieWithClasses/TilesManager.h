#pragma once

#include "TileMap.h"


namespace Managers {

    class TilesManager {
    public:
        class IdPositionSize {
        public:
            const Ids::Ids id;
            const Vector2F position;
            const Vector2F size;
        };
    private:
        TileMap tileMap;
        Vector2F tileDimensions;
        const char* path;
        std::vector<Tiles::Tile*> tiles;
        Vector2U webSpawn;
        Vector2U fireSpawn;

    public:
        TilesManager(std::vector<Tiles::Tile*> tls = {}, Vector2F tileDim = { 0.0f, 0.0f }, const char* p = nullptr);

        ~TilesManager();

        void initialize(GraphicManager* gm, EventManager* em, CollisionManager* cm);

        void draw(GraphicManager* g) const;

        std::vector<IdPositionSize> checkCollisions(const Ids::Ids id, Vector2F pos, Vector2F s);

        std::vector<Tiles::Tile*> getTiles() const;

        void setTiles(Tiles::Tile* newTile);

        void regenTiles();

    private:
        const Vector2F coordinatesForScreen(const Vector2U pos) const;
    };

    using IdPositionSize = TilesManager::IdPositionSize;
}
