#include "Player.h"
#include "stdafx.h"

Entities::Characters::Player::Player(sf::Vector2f pos, sf::Vector2f vel, Ids::Ids ID, const char* tPath) :
    Character(pos, vel, ID, tPath),
    bullet()
{
}

Entities::Characters::Player::Player() :
    Character(),
    bullet()
{
}

Entities::Characters::Player::~Player()
{
}

void Entities::Characters::Player::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM)
{    
    isJumping = false;
	GM->loadTexture(textPath);
	dimensions = static_cast<sf::Vector2u>(GM->getSize(textPath));
	listenKey = EM->addListenKeyboard([this](const sf::Event e) {handleEvents(e); });
	//CM->addCollide(this);
}

void Entities::Characters::Player::setTM(TilesManager* t)
{
    tm = t;
}

void Entities::Characters::Player::setEL(Lists::EntityList* Elist)
{
    EL = Elist;
}

void Entities::Characters::Player::update(float t)
{

    position.x += vel.x * t;
    if (position.x <= dimensions.x * 0.5)
        position.x = (float)(dimensions.x * 0.5);
    else if (position.x >= (32.0f * 200) - dimensions.x)
        position.x = (32.0f * 200) - dimensions.x;
    if (!isJumping && !isGround)
        position.y += vel.y * t + GRAVITY;
    else
        position.y += vel.y * t;
}

void Entities::Characters::Player::draw(Managers::GraphicManager* GM)
{
    GM->draw(textPath, position, scale, { 1, 9 }, { 0, 5 });
	GM->centralize(position);
}

void Entities::Characters::Player::handleEvents(const sf::Event& e)
{
    if (e.type == sf::Event::KeyPressed) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            vel.x = 300;
            scale.x = 1;
            /* code */
            break;
        case sf::Keyboard::Key::A:
            vel.x = -300;
            scale.x = -1;
            /* code */
            break;
        case sf::Keyboard::Key::W:
            while (!isJumping && isGround)
            {
                vel.y = -900;
                isJumping = true;
                isGround = false;
            }
            /* code */
            break;
        case sf::Keyboard::Key::Space:
            EL->insert(createProjectile(ID, position, scale, "../Sprites/bullet.png"));
        default:
            break;
        }
    }
    if (e.type == sf::Event::KeyReleased) {
        switch (e.key.code) {
        case sf::Keyboard::Key::D:
            vel.x = 0;
            break;
        case sf::Keyboard::Key::A:
            vel.x = 0;
            break;
        case sf::Keyboard::Key::W:
            vel.y = 0;
            isJumping = false;
            isGround = false;
            break;
        default:
            break;
        }
    }
}

void Entities::Characters::Player::collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther)
{
    std::string imprimir;

    if (idOther != Ids::ground2 && idOther != Ids::Enemy)
        isGround = false;

    switch (idOther) {
    case Ids::Enemy:
        EL->remove(this);
        break;
    case Ids::ground2:
        isGround = true;
        if (positionOther.y > position.y)
            vel.y = 0;
        //std::cout << isGround << std::endl;
        break;
    case Ids::air:
        vel.y = 0;
        isGround = false;
        isJumping = true;
        break;
    case Ids::wall:
        isGround = true;
        break;
    case Ids::ground4:
        isGround = true;
        break;
    case Ids::lava:
        EL->remove(this);
        break;
    case Ids::ground11:
        isGround = true;
        break;
    default:
        break;
    }
}

void Entities::Characters::Player::createProjectile(Ids::Ids id, sf::Vector2f pos, sf::Vector2f scl, const char* path)
{
    float v;

    scl.x == 1 ? v = 900.0f : v = -900.0f;

    return (new Projectile(pos, sf::Vector2f(v, 0.0f), Ids::Ids::Projectile, path));
}
