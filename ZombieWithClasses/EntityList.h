#ifndef ZOMBIEWITHCLASSES_ENTITYLIST_H
#define ZOMBIEWITHCLASSES_ENTITYLIST_H

#include "List.h"
#include "Entity.h"
#include "GraphicManager.h"
#include "Serialize.h"
#include "json.hpp"

namespace Lists {
    class EntityList : public Serialize {
    private:
        Lists::List<Entities::Entity> list;

    public:
        EntityList();

        ~EntityList();

        void insert(Entities::Entity* pE);

        void remove(Entities::Entity* pE);

        int getSize();

        void update(float t);

        void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);

        void draw();

        Entities::Entity* operator[](int x);

        void destroyEntities();

        nlohmann::json convertJSON();
    };

}

#endif //ZOMBIEWITHCLASSES_ENTITYLIST_H