#include "GraphicManager.h"

#include <iostream>

Managers::GraphicManager::GraphicManager() :
    window{ new sf::RenderWindow(sf::VideoMode(800, 600), "Zombie With Classes") },
    view{ sf::Vector2f(400, 300), sf::Vector2f(400,300) },
    text{ nullptr }
{
    initializeView();
}

Managers::GraphicManager::~GraphicManager()
{
    delete window;

    for (auto i : textures) {
        delete i.second;
    }
}

void Managers::GraphicManager::show() const
{
    window->display();
}

void Managers::GraphicManager::clear(int r, int g, int b)
{
    window->clear(sf::Color(r, g, b));
}

void Managers::GraphicManager::draw(const std::string& path, const Vector2F pos)
{
    if (textures.count(path) == 0) {
        std::cout << "Erro. Imagem em " << path << " nao carregada!" << std::endl;
        exit(714);
    }
    
    text = textures[path];

    sprite.setTexture(*text, true);
    sprite.setScale(0.25, 0.25);
    sprite.setOrigin(text->getSize().x * 0.5, text->getSize().x * 0.5);
    sprite.setPosition(pos.x, pos.y);

    window->draw(sprite);
}

void Managers::GraphicManager::draw(const std::string& path, const Vector2F position, const Vector2U nFrames, const Vector2U frame)
{
    if (textures.count(path) == 0) {
        std::cout << "Atencao! Imagem em " << path << " nao carregada!" << std::endl;
        exit(714);
    }

    text = textures[path];
    sprite.setTexture(*text);


    sf::Vector2i size = { (int)text->getSize().x / (int)nFrames.y, (int)text->getSize().y / (int)nFrames.x };
    sf::Vector2i positionFrame = { (int)size.x * (int)frame.y, (int)size.y * (int)frame.x };

    sprite.setTextureRect({ positionFrame, size });

    sprite.setOrigin({ size.x * 0.5f, size.y * 0.5f });
    sprite.setPosition(size.x, size.y);

    window->draw(sprite);
}

bool Managers::GraphicManager::loadTexture(const std::string& path)
{
    if (textures.count(path) == 1) return true;
    else {
        sf::Texture* text = new sf::Texture();
        if (!text->loadFromFile(path)) {
            std::cout << "Atencao! imagem em " << path << "nao encontrada!" << std::endl;
            exit(715);
        }

        //texturas.insert(std::pair<const std::string, sf::Texture*>(caminho, text));
        textures.emplace(path, text); //c++11
        return true;
    }
}

void Managers::GraphicManager::centralize(const Vector2F centro)
{
    view.setCenter(sf::Vector2f(centro.x, centro.y));
    window->setView(view); //A RenderWindow faz uma cópia da View ao invés de usar o ponteiro, então é preciso a sobre-escrever sempre que for modificada.
}

sf::RenderWindow* Managers::GraphicManager::getWindow() const
{
    return window;
}

const Vector2F Managers::GraphicManager::getSize(const std::string& path) const
{
    if (textures.count(path) == 0) {
        std::cout << "Atencao! Imagem em " << path << " nao carregada!" << std::endl;
        exit(714);
    }

    sf::Vector2u dimensions = (textures.at(path))->getSize();

    return Vector2F(dimensions.x, dimensions.y);
}

void Managers::GraphicManager::initializeView()
{
    window->setView(view);
}
