#ifndef ZOMBIEWITHCLASSES_SPIDERWEB_H
#define ZOMBIEWITHCLASSES_SPIDERWEB_H


#include "Obstacle.h"
#include "Player.h"

namespace Tiles {
    class SpiderWeb :
        public Obstacle {
    public:
        SpiderWeb();

        ~SpiderWeb();

        void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
    };
}


#endif //ZOMBIEWITHCLASSES_SPIDERWEB_H
