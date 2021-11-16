#include "Player.h"

Entities::Characters::Player::Player(Vector2F pos, Vector2F vel, const char* tPath, int h) :
	Character(pos, vel, tPath)
{

}

Entities::Characters::Player::Player() :
	Character()
{
}

Entities::Characters::Player::~Player()
{
}

void Entities::Characters::Player::initialize(Managers::GraphicManager& GM, Managers::EventManager& EM, Managers::CollisionManager& CM)
{
	GM.loadTexture(textPath);
	dimensions = GM.getSize(textPath);
	listenKey = EM.addListenKeyboard([this](const sf::Event e) {handleEvents(e); });
	//CM.addCollide(this);
}

void Entities::Characters::Player::update(float t)
{
    //printf("oi");
	position += 30000 * t;
    /*sf::Event e;
    handleEvents(e);*/
}

void Entities::Characters::Player::draw(Managers::GraphicManager& GM)
{
    //printf("%s\n", textPath);
	GM.draw(textPath, position);
	GM.centralize(position);
}

void Entities::Characters::Player::handleEvents(const sf::Event& e)
{
    if (e.type == sf::Event::KeyPressed) {
        //printf("%f\n", position.x);
        switch (e.key.code) {
        case sf::Keyboard::Key::Right:
            position.x += 30;
            /* code */
            break;
        case sf::Keyboard::Key::Left:
            position.x -= 30;
            /* code */
            break;
        case sf::Keyboard::Key::Up:
            position.y -= 30;
            /* code */
            break;
        case sf::Keyboard::Key::Down:
            position.y += 30;
            /* code */
            break;
        default:
            break;
        }
    }
    else if (e.type == sf::Event::KeyReleased) {
        switch (e.key.code) {
        case sf::Keyboard::Key::Right:
            position.x += 30;
            break;
        case sf::Keyboard::Key::Left:
            position.x -= 30;
            break;
        case sf::Keyboard::Key::Up:
            position.y -= 30;
            break;
        case sf::Keyboard::Key::Down:
            position.y += 30;
            break;
        default:
            break;
        }
    }
}

void Entities::Characters::Player::collide(Ids::Ids idOutro, Vector2F posicaoOutro, Vector2F dimensoesOutro)
{
}
