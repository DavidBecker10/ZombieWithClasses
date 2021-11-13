#pragma once
#include "GraphicManager.h"
#include "CollisionManager.h"
#include "EventManager.h"
#include "Character.h"
#include "EntityList.h"
#include "Player.h"

class Game
{
private:
	Managers::GraphicManager GM;
	Managers::EventManager EM;
	Managers::CollisionManager CM;
	bool close;
	sf::Clock clock;
	Entities::Characters::Player Player1;
	Entities::Characters::Player Player2;
	Lists::EntityList EntityL;

public:
	Game();
	~Game();
	void execute();
};