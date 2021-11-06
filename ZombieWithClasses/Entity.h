#pragma once
#include "SFML/Graphics.hpp"
#include "Ent.h"

namespace Entities
{
    class Entity :
        public Ent
    {
    protected:
        sf::Vector2f position;
        sf::Vector2f vel;

    public:
        Entity(sf::Vector2f pos, sf::Vector2f v);
        Entity();
        ~Entity();
        virtual void move(float t) = 0;
    };
}//a