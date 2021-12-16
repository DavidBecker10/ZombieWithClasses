#include "CollisionManager.h"
#include "stdafx.h"
#include <deque>

namespace Managers {
    CollisionManager::CollisionManager() :
        TM(nullptr),
        EntityL() {

    }

    CollisionManager::~CollisionManager() {
        TM = nullptr;
    }

    bool CollisionManager::isColliding(Entities::Entity* c1, Entities::Entity* c2) {
        Vector2F position1 = c1->getPosition();
        Vector2F dimensions1 = c1->getDimensions();

        Vector2F position2 = c2->getPosition();
        Vector2F dimensions2 = c2->getDimensions();

        Vector2F collision1 = position1 + dimensions1 * .5;
        Vector2F collision2 = position2 + dimensions2 * .5;

        if (c1 == c2) return false;

        return (abs(collision1.x - collision2.x) < (dimensions1.x + dimensions2.x) * 0.5) &&
            (abs(collision1.y - collision2.y) < (dimensions1.y + dimensions2.y) * 0.5);
        return false;
    }

    void CollisionManager::addCollide(Entities::Entity* c) {
        if (c)
            EntityL->insert(c);
        else
            std::cout << "Erro: CollisionManager::addCollide" << std::endl;
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

            std::vector<TilesManager::IdPositionSize> collisionWithTiles = TM->checkCollisions(p1->getID(),
                p1->getPosition(),
                p1->getDimensions());

            for (const TilesManager::IdPositionSize& collision : collisionWithTiles)
                p1->collide(collision.id, collision.position, collision.size);
            for (int j = i + 1; j < EntityL->getSize(); j++) {
                Entities::Entity* p2 = (*EntityL)[j];

                if (isColliding(p1, p2)) {

                    p1->collide(p2->getID(), p2->getPosition(), p2->getDimensions());
                    p2->collide(p1->getID(), p1->getPosition(), p1->getDimensions());

                }
                p1->adjust();
            }
        }
    }

    void CollisionManager::setTilesManager(TilesManager* tm) {
        TM = tm;
    }

    void CollisionManager::setList(Lists::EntityList* EL) {
        EntityL = EL;
    }
}