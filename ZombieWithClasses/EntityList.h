#pragma once

#include "List.h"
#include "Entity.h"
#include "GraphicManager.h"

namespace Lists {
    class EntityList {
    private:
        Lists::List<Entities::Entity> list;

    public:
        EntityList();

        ~EntityList();

        void insert(Entities::Entity* pE);

        void remove(Entities::Entity* pE);

        int getSize();

        void update(float t);

        void initialize(Managers::EventManager* EM, Managers::CollisionManager* CM);

        void draw();

        Entities::Entity* operator[](int x);

        void destroyEntities();
    };

}