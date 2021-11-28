#include "Tile.h"
#include <iostream>

namespace Entities {

    Tile::Tile(const Ids::Ids i, const char* p, Vector2F s) :
        Ent(i, p),
        size{ s }, cm() {

    }

    Tile::~Tile() {
    }

    void Tile::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM) {
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
        default:
            break;
        }
    }

}