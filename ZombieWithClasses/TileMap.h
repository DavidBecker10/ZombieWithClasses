#pragma once
#include "Tile.h"

class TileMap
{

public:
	class TileMapLine
	{
	private:
		const unsigned short* line;
		unsigned int length;

	public:
		TileMapLine(const unsigned short* l = nullptr, unsigned int len = 0);
		~TileMapLine();
		unsigned short operator[](unsigned int i) const;
	};

private:
	Vector2U mapDimensions;
	unsigned short** map;
	const char* path;

public:
	TileMap(const char* filePath = nullptr);
	~TileMap();
	void printMap() const;
	Vector2U getDimensions() const;
	void setTile(Vector2U position, unsigned short newIndex);
	TileMapLine operator[](unsigned int i) const;

	float getDown();
	unsigned short** getMap() const;

private:
	void loadMap();
};
