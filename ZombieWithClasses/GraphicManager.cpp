#include "GraphicManager.h"
#include <iostream>

Managers::GraphicManager::GraphicManager():
window(new sf::RenderWindow(sf::VideoMode(800, 400), "Zombie With Classes"))
{
}

Managers::GraphicManager::~GraphicManager()
{
    delete window;

    for (auto i = text.begin(); i != text.end(); i++)
    {
        delete i->second;
    }
}

void Managers::GraphicManager::show()
{
    window->display();
}

void Managers::GraphicManager::clear(int r, int g, int b)
{
    window->clear(sf::Color(r, g, b));
}

void Managers::GraphicManager::draw(const std::string path, const sf::Vector2f position)
{
    if (!text.count(path)) //Se a textura nao esta no mapa
    {
        std::cout << "Erro. Textura nao carregada em GraphicManager::draw." << std::endl;
        exit(1235);
    }
    
    sf::Texture* nText = text[path];
    sf::Sprite sprite;

    sprite.setTexture(*nText);
    sprite.setPosition(position.x, position.y);

    window->draw(sprite);

}

bool Managers::GraphicManager::loadText(const std::string path)
{
    if (text.count(path)) //Se a textura ja esta no mapa
        return true;
    else
    {
        sf::Texture* nText = new sf::Texture();
        if (nText->loadFromFile(path))  //Se a textura nao esta no mapa, inclui
        {
            //text.insert(std::pair<const std::string, sf::Texture*>(path, nText));
            text.emplace(path, nText);
            return true;
        }
        else
        {
            std::cerr << "Erro ao carregar textura em GraphicManager::loadText." << std::endl;
            exit(1234);
        }
    }
}

void Managers::GraphicManager::center(const sf::Vector2f center)
{
    view.setCenter(sf::Vector2f(center.x, center.y));
}

sf::RenderWindow* Managers::GraphicManager::getWindow()
{
    return window;
}

void Managers::GraphicManager::closeWindow()
{
    window->close();
}
