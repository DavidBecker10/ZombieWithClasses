#pragma once
#include "GraphicManager.h"
#include "EventManager.h"
#include "Character.h"

class Game
{
private:
	Managers::GraphicManager GM;
	Managers::EventManager EM;
	bool close;
	sf::Clock clock;
	Entities::Characters::Character Player;

public:
	Game();
	~Game();
	void execute();
};