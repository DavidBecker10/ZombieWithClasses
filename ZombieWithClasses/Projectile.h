#pragma once
#include "Entity.h"

namespace Entities
{
    class Projectile :
        public Entity
    {
    private:


    public:
        Projectile(sf::Vector2f pos, sf::Vector2f v, Ids::Ids ID, const char* tP);
        Projectile();
        ~Projectile();
        virtual void update(float t);
        void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM);
        void collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther);

    };
}