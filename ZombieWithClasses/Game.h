#pragma once
#include "GraphicManager.h"
#include "EventManager.h"
#include "TilesManager.h"
#include "Character.h"
#include "EntityList.h"
#include "Player.h"
#include "Enemy.h"

class CollisionManager;

class Game
{
private:
	Managers::GraphicManager GM;
	Managers::EventManager EM;
	CollisionManager CM;
	TilesManager TM;
	bool close;
	sf::Clock clock;
	Lists::EntityList EntityL;
	unsigned int IDwindowclosed;

public:
	Game();
	~Game();
	void execute();
	void isWindowClosed(const sf::Event& e);
};