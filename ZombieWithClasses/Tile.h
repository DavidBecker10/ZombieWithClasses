#pragma once

//#include "Vector2D.h"
//#include "Ids.h"
//#include "GraphicManager.h"
#include "Entity.h"
//#include "CollisionManager.h"

namespace Entities {
    class Tile : public Entity {
    protected:
        //        const Ids::Ids id;
        //        const char* path;
        Vector2F size;
        Managers::GraphicManager* gm;
        Managers::CollisionManager* cm;

    public:
        Tile(const Ids::Ids i = Ids::Ids::empty, const char* p = nullptr, Vector2F s = { 32.0f, 32.0f });

        ~Tile();

        void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);

        void draw(const Vector2F position) const;

        void update(float t) {}
        virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
        Vector2F getSize() const { return size; }

    };
}