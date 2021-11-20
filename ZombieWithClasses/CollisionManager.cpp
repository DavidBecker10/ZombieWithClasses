#include "CollisionManager.h"
#include "EntityList.h"
#include "Entity.h"
#include "TilesManager.h"
#include "Vector2D.h"
#include "stdafx.h"


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
    sf::Vector2f position1 = c1->getPosition();
    sf::Vector2u dimensions1 = c1->getDimensions();

    sf::Vector2f position2 = c2->getPosition();
    sf::Vector2u dimensions2 = c2->getDimensions();

    sf::Vector2f distance = position1 - position2;

    if (c1 == c2) return false;

    /*if (position1 == position2)
        return true;*/
    return (fabs(distance.x) < (dimensions1.x + dimensions2.x)/2 && (fabs(distance.y) < (dimensions1.y + dimensions2.y)/2));
    return false;
}

void CollisionManager::addCollide(Entities::Entity* c) {
    if (c)
        EntityL->insert(c);
    else
        std::cout << "Erro: Ponteiro nulo em CollisionManager::addCollide" << std::endl;
}

void CollisionManager::removeCollide(Entities::Entity* c) {
    EntityL->remove(c);
}

void CollisionManager::removeAll() {
    EntityL->destroyEntities();
}

void CollisionManager::verifyCollisions() {
    for (int i = 0; i < EntityL->getSize(); i++) {

        Entities::Entity* p1 = (*EntityL)[i];

        std::vector<TilesManager::infoCollision> collisionWithTiles = TM->checkCollisions(p1->getID(), p1->getPosition(), p1->getDimensions());

        for (TilesManager::infoCollision collision : collisionWithTiles)
            p1->collide(collision.id, collision.position, collision.size);

        for (int j = i + 1; j < EntityL->getSize(); j++) {
            Entities::Entity* p2 = (*EntityL)[j];

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