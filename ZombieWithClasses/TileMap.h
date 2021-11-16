#pragma once
#include "Vector2D.h"

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

private:
	void loadMap();
};
