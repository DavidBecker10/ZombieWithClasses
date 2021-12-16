#include "SpiderWeb.h"

namespace Tiles {
    SpiderWeb::SpiderWeb() :
        Obstacle(Ids::Ids::spiderweb, "../assets/Tiles/Platformer/spiderWeb.png") {
    }

    SpiderWeb::~SpiderWeb() {
    }

    void SpiderWeb::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
        Obstacle::collide(idOther, positionOther, dimensionsOther);
    }

}