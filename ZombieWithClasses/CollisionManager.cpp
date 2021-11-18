#include "CollisionManager.h"
#include "EntityList.h"
#include "Entity.h"
#include "TilesManager.h"
#include "Vector2D.h"
#include <math.h>
#include <vector>
#include <iostream>

CollisionManager::CollisionManager() :
    TM(NULL),
    EntityL()
{

}

CollisionManager::~CollisionManager()
{
    TM = NULL;
}

bool CollisionManager::isColliding(Entities::Entity* c1, Entities::Entity* c2)
{
    Vector2F position1 = c1->getPosition();
    Vector2F dimensions1 = c1->getDimensions();

    Vector2F position2 = c2->getPosition();
    Vector2F dimensions2 = c2->getDimensions();

    Vector2F distance = position1 - position2;

    if (c1 == c2) return false;

    if (position1 == position2)
        return true;
    //return (fabs(distance.x) < (dimensions1.x + dimensions2.x)*0.5) && (fabs(distance.y) < (dimensions1.y + dimensions2.y)*0.5);
    return false;
}

void CollisionManager::addCollide(Entities::Entity* c) {
    list.insert(c);
}

void CollisionManager::removeCollide(Entities::Entity* c) {
    list.erase(c);
}

void CollisionManager::removeAll() {
    list.clear();
}

void CollisionManager::verifyCollisions() {
    for (auto first = list.begin(); first != list.end(); first++) {

        Entities::Entity* p1 = *first;

        auto collisionWithTiles = TM->checkCollisions(p1->getID(), p1->getPosition(), p1->getDimensions());
        //std::cout << p1->getDimensions() << std::endl;
        for (auto collision : collisionWithTiles)
            p1->collide(collision.id, collision.position, collision.size);

        auto second = first;
        second++;

        for (; second != list.end(); second++) {
            Entities::Entity* p2 = *second;

            if (isColliding(p1, p2)) {

                p1->collide(p2->getID(), p2->getPosition(), p2->getDimensions());
                p2->collide(p1->getID(), p1->getPosition(), p1->getDimensions());

            }

        }

        //std::cout << '\n' << std::endl;
    }
}

void CollisionManager::setTilesManager(TilesManager* tm)
{
    TM = tm;
}

void CollisionManager::setList(Lists::EntityList* EL)
{
    EntityL = EL;
}