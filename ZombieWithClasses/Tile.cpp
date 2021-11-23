#include "Tile.h"
#include <iostream>

namespace Entities {

    Tile::Tile(const Ids::Ids i, const char* p, Vector2F s) :
        Entity(Vector2F{ 0.0f,0.0f }, Vector2F{ 0.0f,0.0f }, i, p),
        size{ s }, cm() {

    }

    Tile::~Tile() {
    }

    void Tile::initialize(Managers::EventManager* EM, Managers::CollisionManager* CM) {
        cm = CM;
        GM->loadTexture(textPath);
    }

    /*void Tile::update(float t) {
    }*/

    void Tile::draw(const Vector2F position) const {
        //std::cout<<textPath<<std::endl;
        GM->draw(textPath, position);
    }

    void Tile::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
        switch (idOther) {
        case Ids::Enemy:
            /*...*/
            break;
        case Ids::Player:
            /*...*/
            break;
        default:
            break;
        }
    }

}