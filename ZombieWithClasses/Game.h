#pragma once
#include "GraphicManager.h"
#include "EventManager.h"
#include "Character.h"
#include "EntityList.h"

class Game
{
private:
	Managers::GraphicManager GM;
	Managers::EventManager EM;
	bool close;
	sf::Clock clock;
	Entities::Characters::Character Player1;
	Entities::Characters::Character Player2;
	Lists::EntityList EntityL;

public:
	Game();
	~Game();
	void execute();
};