#ifndef ZOMBIEWITHCLASSES_COLLISIONMANAGER_H
#define ZOMBIEWITHCLASSES_COLLISIONMANAGER_H

#include<set>
class Collide;

namespace Managers {

    class CollisionManager {
    private:
        std::set<Collide*> collides;
        bool isColliding(Collide* c1, Collide* c2);

    public:
        CollisionManager();
        ~CollisionManager();
        void addCollide(Collide* c);
        void removeCollide(Collide* c);
        void removeAll();
        void verifyCollisions();
    };
}

#endif //ZOMBIEWITHCLASSES_COLLISIONMANAGER_H
