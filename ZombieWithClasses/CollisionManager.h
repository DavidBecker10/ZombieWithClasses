#ifndef ZOMBIEWITHCLASSES_COLLISIONMANAGER_H
#define ZOMBIEWITHCLASSES_COLLISIONMANAGER_H

#include "Entity.h"
#include "EntityList.h"
#include <set>
#include "TilesManager.h"

namespace Managers {

    class CollisionManager {
    private:
        TilesManager* TM;
        Lists::EntityList* EntityL;

    public:
        CollisionManager();
        ~CollisionManager();
        void addCollide(Entities::Entity* c);
        void removeCollide(Entities::Entity* c);
        void removeAll();
        void verifyCollisions();
        void setTilesManager(TilesManager* tm);
        void setList(Lists::EntityList* EL);

    private:
        bool isColliding(Entities::Entity* c1, Entities::Entity* c2);
    };
}

#endif //ZOMBIEWITHCLASSES_COLLISIONMANAGER_H
