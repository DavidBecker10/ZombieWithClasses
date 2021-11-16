#include "CollisionManager.h"
#include "Collide.h"

#include "Vector2D.h"

#include <math.h>

#include <iostream>


Managers::CollisionManager::CollisionManager() {

}

Managers::CollisionManager::~CollisionManager() {

}

bool Managers::CollisionManager::isColliding(Collide* c1, Collide* c2) {
   /* Vector2F position1 = c1->getPosition();
    Vector2F dimensions1 = c1->getDimensions();

    Vector2F position2 = c2->getPosition();
    Vector2F dimensions2 = c2->getDimensions();

    Vector2F distance = position1 - position2;

    if (c1 == c2) return false;

    return (fabs(distance.x) < (dimensions1.x + dimensions2.x) / 2.) && (fabs(distance.y) < (dimensions1.y + dimensions2.y) / 2.);*/
    return false;
}

void Managers::CollisionManager::addCollide(Collide* c) {
   // collides.insert(c);
}

void Managers::CollisionManager::removeCollide(Collide* c) {
    //collides.erase(c);
}

void Managers::CollisionManager::removeAll() {
    //collides.clear();
}

void Managers::CollisionManager::verifyCollisions() {
   /* for (auto first = collides.begin(); first != collides.end(); first++) {
        auto second = first;
        second++;
        for (; second != collides.end(); second++) {
            Collide* p1 = *first;
            Collide* p2 = *second;
            if (isColliding(p1, p2)) {
                p1->collide(p2->getID(), p2->getPosition(), p2->getDimensions());
                p2->collide(p1->getID(), p1->getPosition(), p1->getDimensions());
            }
        }
    }*/
}