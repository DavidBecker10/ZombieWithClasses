#include "GraphicManager.h"
#include <iostream>
#include "stdafx.h"

Managers::GraphicManager::GraphicManager() :
    window{ new sf::RenderWindow(sf::VideoMode(1280, 720), "Zombie With Classes", sf::Style::Close) },
    view{ sf::Vector2f(640, 360), sf::Vector2f(1280,720) },
    text{ nullptr }
{
    initializeView();
    font.loadFromFile(FONT_PATH);
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

void Managers::GraphicManager::draw(const std::string& path, Vector2F pos)
{
    if (textures.count(path) == 0) {
        std::cout << "Erro: Imagem em " << path << " nao carregada!" << std::endl;
        exit(714);
    }

    text = textures[path];

    /*body.setTexture(*text, true);
    body.setScale(1, 1);
    body.setOrigin(text->getSize().x * 0.5, text->getSize().x * 0.5);
    body.setPosition(pos.x, pos.y);

    window->draw(body);*/

    sprite.setTexture(*text, true);
    //sprite.setTextureRect(text->getSize();)
    sprite.setScale(1, 1);
    sprite.setOrigin(text->getSize().x * 0.5, text->getSize().x * 0.5);
    sprite.setPosition(pos.x, pos.y);

    window->draw(sprite);
}

void Managers::GraphicManager::draw(const std::string& path, Vector2F pos, Vector2F scale)
{
    if (textures.count(path) == 0) {
        std::cout << "Erro: Imagem em " << path << " nao carregada!" << std::endl;
        exit(714);
    }

    text = textures[path];

    sprite.setTexture(*text, true);
    sprite.setScale(scale.x, scale.y);
    sprite.setOrigin(text->getSize().x * 0.5, text->getSize().x * 0.5);
    sprite.setPosition(pos.x, pos.y);

    window->draw(sprite);
}

void Managers::GraphicManager::draw(const std::string& path, Vector2F position, Vector2U nFrames, Vector2U frame)
{
    if (textures.count(path) == 0) {
        std::cout << "Erro: Imagem em " << path << " nao carregada!" << std::endl;
        exit(714);
    }

    text = textures[path];
    //body.setTexture(*text, true);
    sprite.setTexture(*text, true);

    sf::Vector2i size = { (int)text->getSize().x / (int)nFrames.y, (int)text->getSize().y / (int)nFrames.x };
    sf::Vector2i positionFrame = { (int)size.x * (int)frame.y, (int)size.y * (int)frame.x };

    //body->setTextureRect({ positionFrame, size });
    //body.setScale(scale);
    //body.setOrigin(text->getSize().x * 0.5, text->getSize().x * 0.5);
    //body.setPosition(position.x, position.y);
    //body->setOrigin({ size.x * 0.5f, size.y * 0.5f });
    //body->setPosition(size.x, size.y);
    //window->draw(body);

    sprite.setTextureRect({ positionFrame, size });

    sprite.setOrigin(text->getSize().x * 0.5, text->getSize().x * 0.5);
    sprite.setPosition(position.x, position.y);
    window->draw(sprite);

}

bool Managers::GraphicManager::loadTexture(const std::string& path)
{
    if (textures.count(path) == 1) return true;
    else {
        sf::Texture* text = new sf::Texture();
        if (!text->loadFromFile(path)) {
            std::cout << "Error: Image in: " << path << " not found!" << std::endl;
            exit(715);
        }

        //texturas.insert(std::pair<const std::string, sf::Texture*>(caminho, text));
        textures.emplace(path, text); //c++11
        return true;
    }
}

void Managers::GraphicManager::centralize(Vector2F centro)
{
    view.setCenter(sf::Vector2f(centro.x, centro.y));
    window->setView(view);
}

sf::RenderWindow* Managers::GraphicManager::getWindow() const
{
    return window;
}

const Vector2F Managers::GraphicManager::getSize(const std::string& path) const
{
    if (textures.count(path) == 0) {
        std::cout << "Error: Image in: " << path << " not loaded!" << std::endl;
        exit(714);
    }

    sf::Vector2u dimensions = (textures.at(path))->getSize();

    return Vector2F(dimensions.x, dimensions.y);
}

void Managers::GraphicManager::initializeView()
{
    window->setView(view);
}

void Managers::GraphicManager::drawSolidRectangle(Vector2F center, Vector2F dimensions, const sf::Color color) {
    sf::RectangleShape rect = sf::RectangleShape({ dimensions.x, dimensions.y });
    /*rect.setFillColor({ 128, 128, 128, 255});*/
    rect.setFillColor(color);
    rect.setOrigin(dimensions.x / 2, dimensions.y / 2);
    rect.setPosition(center.x, center.y);
    window->draw(rect);
}

void Managers::GraphicManager::drawText(const std::string text, Vector2F position, unsigned int size,
    const bool centralize, sf::Color color) const {
    sf::Text txt = sf::Text(text, font, size);
    txt.setFillColor(color);
    if (centralize) {
        sf::FloatRect siz = txt.getGlobalBounds();
        txt.setOrigin(siz.width / 2, siz.height / 2);
    }
    txt.setPosition(position.x, position.y);
    window->draw(txt);
}

Vector2F Managers::GraphicManager::getMousePosition() const {
    sf::Vector2i relativePos = sf::Mouse::getPosition(*window);
    sf::Vector2u windowSize = window->getSize();
    sf::Vector2f viewSize = view.getSize();
    sf::Vector2f viewPos = view.getCenter() - viewSize / 2.0f;

    return {
            (relativePos.x / (float)windowSize.x) * viewSize.x + viewPos.x,
            (relativePos.y / (float)windowSize.y) * viewSize.y + viewPos.y
    };
}
