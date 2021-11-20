#include "TileMap.h"
#include "json.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

using TileMapLine = TileMap::TileMapLine;

TileMapLine::TileMapLine(unsigned short* l, unsigned int len):
    line(l),
    length(len)
{
}

TileMapLine::~TileMapLine()
{
}

unsigned short TileMapLine::operator[](unsigned int i) const
{
    if (i >= length)
    {
        std::cout << "Erro. Segmentation fault em TileMapLine::operator[]." << std::endl;
        exit(1235);
    }
    return line[i];
}

TileMap::TileMap(const char* filePath):
    map{ NULL },
    path{filePath}
{
    if (path) loadMap();
}

TileMap::~TileMap()
{
    if (map)
    {
        for (unsigned int i = 0; i < mapDimensions.y; i++)
            delete map[i];

        delete map;
    }
}

void TileMap::printMap() const
{
    for (unsigned int i = 0; i < mapDimensions.y; i++)
    {
        for (unsigned int j = 0; j < mapDimensions.x; j++)
            std::cout << std::setw(2) << map[i][j] << ' ';
        std::cout << std::endl;;
    }

    std::cout.flush();
}

sf::Vector2u TileMap::getDimensions() const
{
    return sf::Vector2u(mapDimensions.x, mapDimensions.y);
}

void TileMap::setTile(sf::Vector2u position, unsigned short newIndex)
{
    if (position.x >= mapDimensions.x || position.y >= mapDimensions.y)
    {
        std::cout << "Erro. Segmentation fault em TileMap::setTile." << std::endl;
        exit(1235);
    }

    map[position.y][position.x] = newIndex;
}

const TileMapLine TileMap::operator[](unsigned int i) const
{
    if (i > mapDimensions.y)
    {
        std::cout << "Erro. Segmentation fault em TileMap::setTile." << std::endl;
        exit(1235);
    }

    return { map[i], mapDimensions.x };
}

float TileMap::getDown()
{
    return  0;// posTile.y - tile.getSize() * 0.5;
}

unsigned short** TileMap::getMap() const
{
    return map;
}


void TileMap::loadMap()
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cout << "Erro. Arquivo no caminho " << path << " nao pode ser aberto." << std::endl;
        exit(1236);
    }

    nlohmann::json json;

    file >> json;

    json = json["layers"][0];

    mapDimensions = { json["width"], json["height"] };

    //std::cout << mapDimensions << std::endl;

    json = json["data"];

    map = new unsigned short*[mapDimensions.y];

    for (int i = 0; i < mapDimensions.y; i++) map[i] = new unsigned short[mapDimensions.x];

    unsigned short i = 0;
    unsigned short j = 0;

    for (unsigned short s : json)
    {
        if (j >= mapDimensions.x)
        {
            j = 0;
            ++i;
        }

        if (i >= mapDimensions.y) break;
        
        map[i][j++] = s;
    }
    //printf("%f", getDown());
    //printMap();
}
