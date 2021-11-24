#include "PlayerTwo.h"

Entities::Characters::PlayerTwo::PlayerTwo(Vector2F pos, const char* path):
	Player(pos, path)
{

}

Entities::Characters::PlayerTwo::~PlayerTwo()
{
}

void Entities::Characters::PlayerTwo::handleEvents(const sf::Event& e)
{
    if (e.type == sf::Event::KeyPressed) {
        switch (e.key.code) {
        case sf::Keyboard::Key::Right:
            vel.x = 300;
            scale.x = 1;
            /* code */
            break;
        case sf::Keyboard::Key::Left:
            vel.x = -300;
            scale.x = -1;
            /* code */
            break;
        case sf::Keyboard::Key::Up:
            if (!isJumping && isGround) {
                vel.y = -900.0f;
                isJumping = true;
                isGround = false;
            }
            /* code */
            break;
        case sf::Keyboard::Key::Enter:
            createProjectile(ID, position, BULLET_PATH);
        default:
            break;
        }
    }
    if (e.type == sf::Event::KeyReleased) {
        switch (e.key.code) {
        case sf::Keyboard::Key::Right:
            vel.x = 0;
            scale.x = 1;
            /* code */
            break;
        case sf::Keyboard::Key::Left:
            vel.x = 0;
            scale.x = -1;
            /* code */
            break;
        case sf::Keyboard::Key::Up:
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