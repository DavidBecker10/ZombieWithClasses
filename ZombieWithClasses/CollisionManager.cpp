#include "CollisionManager.h"
#include "EntityList.h"
#include "Entity.h"
#include "TilesManager.h"
#include "Vector2D.h"
#include <math.h>
#include <iostream>


Managers::CollisionManager::CollisionManager() {

}

Managers::CollisionManager::~CollisionManager() {

}

bool Managers::CollisionManager::isColliding(Entities::Entity* c1, Entities::Entity* c2) {
    Vector2F position1 = c1->getPosition();
    Vector2F dimensions1 = c1->getDimensions();

    Vector2F position2 = c2->getPosition();
    Vector2F dimensions2 = c2->getDimensions();

    Vector2F distance = position1 - position2;

    if (c1 == c2) return false;

    return (fabs(distance.x) < (dimensions1.x + dimensions2.x) / 2.) && (fabs(distance.y) < (dimensions1.y + dimensions2.y) / 2.);
    return false;
}

/*void Managers::CollisionManager::addCollide(Entities::Entity* c) {
    EList->insert(c);
}*/

/*void Managers::CollisionManager::removeCollide(Entities::Entity* c) {
    EList->remove(c);
}*/

/*void Managers::CollisionManager::removeAll() {
    EList->destroyEntities();
}*/

void Managers::CollisionManager::verifyCollisions() {
    for (int i = 0; i < EList->getSize(); i++) {
        Entities::Entity* p1 = NULL;
        p1 = (*EList)[i];

        for (int j = i + 1; j < EList->getSize(); j++) {
            Entities::Entity* p2 = NULL;
            p2 = (*EList)[j];
            if (isColliding(p1, p2)) {
                p1->collide(p2->getID(), p2->getPosition(), p2->getDimensions());
                p2->collide(p1->getID(), p1->getPosition(), p1->getDimensions());
            }
        }
    }
}

void Managers::CollisionManager::setTilesManager(TilesManager* tm)
{
    TM = tm;
}

void Managers::CollisionManager::setList(Lists::EntityList* EL)
{
    EList = EL;
}