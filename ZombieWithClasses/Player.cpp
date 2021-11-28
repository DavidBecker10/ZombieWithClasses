#include "Player.h"
#include "CollisionManager.h"
#include "Ids.h"

Entities::Characters::Player::Player(Vector2F pos, const char* path, Ids::Ids id) :
    Character(pos, id, path, 7), p2(NULL), bullet(), frameSHOT(0), isEnd(false) {

}

Entities::Characters::Player::~Player() {
    p2 = NULL;
    bullet = NULL;
}

void Entities::Characters::Player::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM,
    Managers::CollisionManager* CM) {
    frame = 0;
    isJumping = false;
    //isGround = false;
    GM->loadTexture(textPath);
    //dimensions = static_cast<sf::Vector2u>(GM->getSize(textPath));
    dimensions = GM->getSize(textPath);
    listenKey = EM->addListenKeyboard([this](const sf::Event e) { handleEvents(e); });
    //CM->addCollide(this);

}

//void Entities::Characters::Player::setTM(Managers::TilesManager *t) {
//    TM = t;
//}

void Entities::Characters::Player::update(float t) {
    frameSHOT += t;
    frame += t;
    if (p2) {
        centralizeInView();
    }
    position.x += vel.x * t;
    if (position.x < dimensions.x * 0.5)
        position.x = (float)(dimensions.x * 0.5);
    else if (position.x > (32.0f * 200) - dimensions.x) {
        position.x = (32.0f * 200) - dimensions.x;
        isEnd = true;
    }
    if (!isGround && !isJumping)
        position.y += vel.y * t + GRAVITY;
    else
        position.y += vel.y * t;
    //std::cout<< position.y << std::endl;
}

void Entities::Characters::Player::draw() {
    //GM->draw(textPath, position, body, { 1, 9 }, { 0, 5 });
    GM->draw(textPath, position, scale);
    //GM->centralize(position);
}

void Entities::Characters::Player::handleEvents(const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            vel.x = 400;
            scale.x = 1;
            /* code */
            break;
        case sf::Keyboard::Key::A:
            vel.x = -400;
            scale.x = -1;
            /* code */
            break;
        case sf::Keyboard::Key::W:
            if (!isJumping && isGround) {
                vel.y = -900.0f;
                isJumping = true;
                isGround = false;
            }
            break;
        case sf::Keyboard::Key::Space:
            if (frameSHOT > 0.5) {
                createProjectile(position);
                frameSHOT = 0;
            }
        default:
            break;
        }
    }
    if (e.type == sf::Event::KeyReleased) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            vel.x = 0;
            scale.x = 1;
            /* code */
            break;
        case sf::Keyboard::Key::A:
            vel.x = 0;
            scale.x = -1;
            /* code */
            break;
        case sf::Keyboard::Key::W:
            vel.y = 0;
            isJumping = false;
            isGround = false;

            /* code */
            break;
            //            case sf::Keyboard::Key::Space:
            //                createProjectile(ID, position, BULLET_PATH);
        default:
            break;
        }
    }
}

void Entities::Characters::Player::collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther) {
    std::cout << idOther << std::endl;
    if (idOther != Ids::ground2 && idOther != Ids::Enemy)
        isGround = false;

    switch (idOther) {
    case Ids::Ghoul:
        if (frame > 0.4) {
            life--;
            frame = 0;
        }
        isGround = true;
        break;
    case Ids::Homer:
        if (frame > 0.4) {
            life--;
            frame = 0;
        }
        isGround = true;
        break;
    case Ids::Nemesis:
        if (frame > 0.4) {
            life--;
            frame = 0;
        }
        isGround = true;
        break;
    case Ids::ground2:
        isGround = true;
        if (positionOther.y > position.y)
            vel.y = 0;
        break;
    case Ids::air:
        vel.y = 0;
        isGround = false;
        isJumping = true;
        break;
    case Ids::Bullet:
        isGround = true;
        break;
    case Ids::Bone:
        if (frame > 0.4) {
            life -= 2;
            frame = 0;
        }
        isGround = true;
        break;
    case Ids::lava:
        if (frame > 0.4) {
            life--;
            frame = 0;
        }
        //position.y += -10.0;
        isGround = true;
        break;
    case Ids::ground11:
        isGround = true;
        break;
    case Ids::wallR:
        isGround = true;
        break;
    case Ids::wallL:
        isGround = false;
        break;
    case Ids::Player2:
        if (!isJumping)
            isGround = true;
    case Ids::spiderweb:
        vel.x *= 0.8;
        isGround = true;
        break;
    default:
        break;
    }
}


void Entities::Characters::Player::createProjectile(Vector2F pos) {
    float v, px;
    bool dir;

    scale.x == 1 ? dir = true : dir = false;

    scale.x == 1 ? v = 800.0f : v = -800.0f;

    scale.x == 1 ? px = 35.0f : px = -35.0f;

    bullet = new Bullet(Vector2F(pos.x + px, pos.y + 20.0f), Vector2F(v, 0.0f), dir);

    EL->insert(bullet);
}


void Entities::Characters::Player::initializeJSON(nlohmann::json j) {
    position = { j["position"] };
    life = { j["life"] };
}

void Entities::Characters::Player::centralizeInView()
{
    if (position.x <= (GM->getCenterView().x) - (GM->getSizeView().x / 2) + dimensions.x / 2)
        position.x = (GM->getCenterView().x) - (GM->getSizeView().x / 2) + dimensions.x / 2;

    else if (position.x >= (GM->getCenterView().x) + (GM->getSizeView().x / 2) - dimensions.x / 2)
        position.x = (GM->getCenterView().x) + (GM->getSizeView().x / 2) - dimensions.x / 2;
}
