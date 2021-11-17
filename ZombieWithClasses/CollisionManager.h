#ifndef ZOMBIEWITHCLASSES_COLLISIONMANAGER_H
#define ZOMBIEWITHCLASSES_COLLISIONMANAGER_H
#include "EntityList.h"

class TilesManager;

namespace Managers {

    class CollisionManager {
    private:
        
        bool isColliding(Entities::Entity* c1, Entities::Entity* c2);
        TilesManager* TM;
        Lists::EntityList* EList;

    public:
        CollisionManager();
        ~CollisionManager();
        //void addCollide(Entities::Entity* c);
        //void removeCollide(Entities::Entity* c);
        //void removeAll();
        void verifyCollisions();
        void setTilesManager(TilesManager* tm);
        void setList(Lists::EntityList* EL);
    };
}

#endif //ZOMBIEWITHCLASSES_COLLISIONMANAGER_H
