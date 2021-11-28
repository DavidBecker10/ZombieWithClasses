#ifndef ZOMBIEWITHCLASSES_LAVA_H
#define ZOMBIEWITHCLASSES_LAVA_H

#include "Obstacle.h"
#include "PlayerTwo.h"
class Lava : public Obstacle {
private:
    Entities::Characters::Player* player1;
    Entities::Characters::PlayerTwo* player2;
public:
    Lava();
    ~Lava();
    void setPlayers(Entities::Characters::Player* p1, Entities::Characters::PlayerTwo* p2) { player1 = p1; player2 = p2; }
    void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
};


#endif //ZOMBIEWITHCLASSES_LAVA_H
