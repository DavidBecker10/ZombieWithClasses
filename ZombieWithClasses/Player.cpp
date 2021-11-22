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

void Entities::Characters::Player::update(float t)
{
    position.x += vel.x * t;
    if (position.x <= dimensions.x * 0.5)
        position.x = (float)(dimensions.x * 0.5);
    else if (position.x >= (32.0f * 200) - dimensions.x)
        position.x = (32.0f * 200) - dimensions.x;
    if (!isGround && !isJumping)
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
            vel.y = -900.0f;
            /* code */
            break;
        case sf::Keyboard::Key::Space:
            createProjectile(ID, position,  "../Sprites/bullet.png");
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
            vel.y = 900.0f;
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
        if (position.y > positionOther.y - dimensionsOther.y / 2)
            position.y -= 1.0f;
        isGround = true;
        vel.y = 0;
        //std::cout << isGround << std::endl;
        break;
    case Ids::air:
        vel.y = 0;
        isGround = false;
        isJumping = true;
        break;
    case Ids::wallR:
        isGround = true;
        break;
    case Ids::Projectile:
        isGround = true;
        break;
    case Ids::lava:
        EL->remove(this);
        break;
    case Ids::ground11:
        isGround = true;
        break;
    case Ids::wallL:
        isGround = false;
        break;
    default:
        break;
    }
}

void Entities::Characters::Player::createProjectile(Ids::Ids id, sf::Vector2f pos, const char* path)
{
    float v, px;
    bool dir;

    scale.x == 1 ? dir = true : dir = false;

    scale.x == 1 ? v = 900.0f : v = -900.0f;

    scale.x == 1 ? px = 35.0f : px = -35.0f;

    bullet = new Projectile(sf::Vector2f(pos.x + px, pos.y + 20.0f), sf::Vector2f(v, 0.0f), Ids::Ids::Projectile, path, dir);

    EL->insert(bullet);
}