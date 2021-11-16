//
// Created by Gabriel on 10/11/2021.
//

#ifndef ZOMBIEWITHCLASSES_COLLISIONMANAGER_H
#define ZOMBIEWITHCLASSES_COLLISIONMANAGER_H

#include<set>

namespace Managers {

    class Collide;

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
