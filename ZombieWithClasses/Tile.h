#pragma once
#include "Vector2D.h"
#include "Ids.h"
#include "CollisionManager.h"
#include "GraphicManager.h"

namespace Entities
{
	class Tile :
		public Entity
	{
	private:
		const Ids::Ids id;
		const char* path;
		sf::Vector2f size;
		Managers::GraphicManager* gm;
		CollisionManager* cm;


	public:
		Tile(const Ids::Ids i, const char* p, sf::Vector2f s);
		Tile();
		~Tile();
		virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM);
		virtual void update(float t);
		void draw(Managers::GraphicManager& g, const sf::Vector2f position) const;
		const Ids::Ids getID() const;
		sf::Vector2f getSize() const;
		void setPosition(sf::Vector2f pos);
		sf::Vector2f getPosition() const;
		virtual void collide(Ids::Ids idOther, sf::Vector2f positionOther, sf::Vector2u dimensionsOther, bool isAbove);
	};
}