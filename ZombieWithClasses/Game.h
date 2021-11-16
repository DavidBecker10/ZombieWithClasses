#pragma once
#include "GraphicManager.h"
#include "CollisionManager.h"
#include "EventManager.h"
#include "TilesManager.h"
#include "Character.h"
#include "EntityList.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
private:
	Managers::GraphicManager GM;
	Managers::EventManager EM;
	Managers::CollisionManager CM;
	TilesManager TM;
	bool close;
	sf::Clock clock;
	Entities::Characters::Player Player1;
	Entities::Characters::Player Player2;
	Entities::Characters::Enemy Zombie;
	Lists::EntityList EntityL;
	unsigned int IDwindowclosed;

public:
	Game();
	~Game();
	void execute();
	void isWindowClosed(const sf::Event& e);
};