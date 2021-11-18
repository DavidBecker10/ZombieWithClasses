#pragma once
#include "Vector2D.h"
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
		TileMapLine(unsigned short* l, unsigned int len);
		~TileMapLine();
		unsigned short operator[](unsigned int i) const;
	};
	 
private:
	Entities::Tile tile;
	Vector2U mapDimensions;
	unsigned short** map;
	const char* path;

public:
	TileMap(const char* filePath = NULL);
	~TileMap();
	void printMap() const;
	Vector2U getDimensions() const;
	void setTile(Vector2U position, unsigned short newIndex);
	const TileMapLine operator[](unsigned int i) const;
	float getDown();
	unsigned short** getMap() const;

private:
	void loadMap();
};
