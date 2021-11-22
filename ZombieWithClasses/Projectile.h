#pragma once
#include "Entity.h"
#include "EntityList.h"

namespace Entities
{
    class Projectile :
        public Entity
    {
    private:

    public:
        Projectile(sf::Vector2f pos, sf::Vector2f v, Ids::Ids ID, const char* tP, bool dir);
        Projectile();
        ~Projectile();
        virtual void update(float t);
        void draw(Managers::GraphicManager* g);
        void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM);
        void collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther);
    };
}