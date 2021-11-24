#include "PlayerOne.h"

Entities::Characters::PlayerOne::PlayerOne(Vector2F pos, const char* path):
	Player(pos, path)
{

}

Entities::Characters::PlayerOne::~PlayerOne()
{
}

void Entities::Characters::PlayerOne::handleEvents(const sf::Event& e)
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
            if (!isJumping && isGround) {
                vel.y = -900.0f;
                isJumping = true;
                isGround = false;
            }
            /* code */
            break;
        case sf::Keyboard::Key::Space:
            createProjectile(ID, position, BULLET_PATH);
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
        default:
            break;
        }
    }
}
