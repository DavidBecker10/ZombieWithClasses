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
		Vector2F size;
		Managers::GraphicManager* gm;
		CollisionManager* cm;


	public:
		Tile(const Ids::Ids i, const char* p, Vector2F s);
		Tile();
		~Tile();
		virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, CollisionManager* CM);
		virtual void update(float t);
		void draw(Managers::GraphicManager& g, const Vector2F position) const;
		const Ids::Ids getID() const;
		Vector2F getSize() const;
		void setPosition(Vector2F pos);
		Vector2F getPosition() const;
		virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
	};
}