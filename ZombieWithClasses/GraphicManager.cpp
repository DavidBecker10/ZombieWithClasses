#include "GraphicManager.h"

#include <iostream>

Managers::GraphicManager::GraphicManager() :
    window{ new sf::RenderWindow(sf::VideoMode(800, 600), "Zombie With Classes", sf::Style::Close) },
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

void Managers::GraphicManager::draw(const std::string& path, const sf::Vector2f pos, sf::Sprite body)
{
    if (textures.count(path) == 0) {
        std::cout << "Erro: Imagem em " << path << " nao carregada!" << std::endl;
        exit(714);
    }
    
    text = textures[path];

    body.setTexture(*text, true);
    //sprite.setTextureRect(text->getSize());
    body.setScale(1, 1);
    body.setOrigin(text->getSize().x * 0.5, text->getSize().x * 0.5);
    body.setPosition(pos.x, pos.y);

    window->draw(body);
}

void Managers::GraphicManager::draw(const std::string& path, const sf::Vector2f position, sf::Sprite body, sf::Vector2f scale, const sf::Vector2u nFrames, const sf::Vector2u frame)
{
    if (textures.count(path) == 0) {
        std::cout << "Erro: Imagem em " << path << " nao carregada!" << std::endl;
        exit(714);
    }

    text = textures[path];
    body.setTexture(*text, true);

    //sf::Vector2i size = { (int)text->getSize().x / (int)nFrames.y, (int)text->getSize().y / (int)nFrames.x };
    //sf::Vector2i positionFrame = { (int)size.x * (int)frame.y, (int)size.y * (int)frame.x };

    //body->setTextureRect({ positionFrame, size });
    body.setScale(scale);
    body.setOrigin(text->getSize().x * 0.5, text->getSize().x * 0.5);
    body.setPosition(position.x, position.y);
    //body->setOrigin({ size.x * 0.5f, size.y * 0.5f });
    //body->setPosition(size.x, size.y);
    
    window->draw(body);
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

void Managers::GraphicManager::centralize(const sf::Vector2f centro)
{
    view.setCenter(sf::Vector2f(centro.x, centro.y));
    window->setView(view);
}

sf::RenderWindow* Managers::GraphicManager::getWindow() const
{
    return window;
}

const sf::Vector2f Managers::GraphicManager::getSize(const std::string& path) const
{
    if (textures.count(path) == 0) {
        std::cout << "Erro: Imagem em " << path << " nao carregada!" << std::endl;
        exit(714);
    }

    sf::Vector2u dimensions = (textures.at(path))->getSize();

    return sf::Vector2f(dimensions.x, dimensions.y);
}

void Managers::GraphicManager::initializeView()
{
    window->setView(view);
}
