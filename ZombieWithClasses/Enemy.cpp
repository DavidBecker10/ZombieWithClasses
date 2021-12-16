#include "Enemy.h"
#include "stdafx.h"
#include "CollisionManager.h"

Entities::Characters::Enemy::Enemy(Vector2F pos, Ids::Ids id, const char* tPath, int lf, Player* p1, PlayerTwo* p2) :
    Character(pos, id, tPath, lf), player1(p1), player2(p2) {
    frame = 1;
    faceLeft = true;
}

Entities::Characters::Enemy::~Enemy() {
    player1 = nullptr;
    player2 = nullptr;
}

void Entities::Characters::Enemy::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM,
    Managers::CollisionManager* CM) {
    isGround = false;
    GM->loadTexture(textPath);
    dimensions = GM->getSize(textPath);

}

void Entities::Characters::Enemy::draw() {
    GM->draw(textPath, position, scale);
}

void Entities::Characters::Enemy::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    if (idOther == Ids::Bullet) {
        if (frame > 0.4) {
            energy--;
            frame = 0;
        }
        if (energy <= 0) {
            player1->incrementScore(10);
        }
        isGround = true;
    }
    else if (idOther == Ids::ground || idOther == Ids::dirt || idOther == Ids::lava) {
        isGround = true;
        float dist_x = (dimensions.x + dimensionsOther.x / 2) - std::abs(position.x + dimensions.x / 2 - positionOther.x - dimensionsOther.x / 2);
        float dist_y = (dimensions.y + dimensionsOther.y / 2) - std::abs(position.y + dimensions.y / 2 - positionOther.y - dimensionsOther.y / 2);

        if (dist_x * dist_y > .001 * dimensions.x * dimensions.y) {
            if (dist_x < dist_y) {
                if (dist_x > std::abs(adjusts.x)) {
                    if (position.x + dimensions.x / 2 > positionOther.x + dimensionsOther.x / 2) {
                        adjusts.x = dist_x * 1;
                    }
                    else {
                        adjusts.x = dist_x * -1;
                    }
                }
            }
            else {
                if (dist_y > std::abs(adjusts.y)) {
                    if (position.y + dimensions.y / 2 > positionOther.y + dimensionsOther.y / 2) {
                        adjusts.y = dist_y * 1;
                    }
                    else {
                        adjusts.y = dist_y * -1;
                    }
                }
            }
        }
    }
    else if (idOther == Ids::empty) {
        isGround = false;
    }
    else {
        isGround = true;
    }
}

nlohmann::json Entities::Characters::Enemy::convertJSON() {
    return {
            { "ID",      ID},
            {"position", position.convertJSON()},
            {"life",     energy},
            {"Stage",    currentStage}
    };
}

float Entities::Characters::Enemy::distancePlayer() {
    if (player2 != nullptr) {
        float dist = fabs(position.x - player1->getPosition().x);
        float dist2 = fabs(position.x - player2->getPosition().x);
        if (dist < dist2) {
            if (position.x > player1->getPosition().x) {
                scale.x = 1;
                faceLeft = true;
                return position.x - player1->getPosition().x;
            }
            else {
                scale.x = -1;
                faceLeft = false;
                return player1->getPosition().x - position.x;
            }
        }
        else {
            if (position.x > player2->getPosition().x) {
                scale.x = 1;
                faceLeft = true;
                return position.x - player2->getPosition().x;
            }
            else {
                scale.x = -1;
                faceLeft = false;
                return player2->getPosition().x - position.x;
            }
        }
    }
    else {
        if (position.x > player1->getPosition().x) {
            scale.x = 1;
            faceLeft = true;
            return position.x - player1->getPosition().x;
        }
        else {
            scale.x = -1;
            faceLeft = false;
            return player1->getPosition().x - position.x;
        }
    }
}

void Entities::Characters::Enemy::update(float t) {

}

void Entities::Characters::Enemy::adjust() {
    if (adjusts.y < 0) {
        vel = Vector2F();
        vel.y = 0;
        vel.x = 0;
    }
    else if (adjusts.y > 0) {
        vel.y = 0;
    }
    Entity::adjust();
}