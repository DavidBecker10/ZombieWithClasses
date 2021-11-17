#include "EntityList.h"
#include "CollisionManager.h"

Lists::EntityList::EntityList() :
	list()
{

}

Lists::EntityList::~EntityList()
{
	list.destroy();
}

void Lists::EntityList::insert(Entities::Entity* pE)
{
	if (pE)
		list.insert(pE);
	else
		std::cerr << "Erro. Ponteiro pE nulo em Lists::EntityList::insert" << std::endl;
}

void Lists::EntityList::remove(Entities::Entity* pE)
{
	list.remove(pE);
}

int Lists::EntityList::getSize()
{
	return list.getSize();
}

void Lists::EntityList::update(float t)
{
	for (int i = 0; i < list.getSize(); i++)
		list[i]->update(t);
}

void Lists::EntityList::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM)
{
	for (int i = 0; i < list.getSize(); i++)
		list[i]->initialize(GM, EM);
}

void Lists::EntityList::draw(Managers::GraphicManager* g)
{
	for (int i = 0; i < list.getSize(); i++)
		list[i]->draw(g);
}

Entities::Entity* Lists::EntityList::operator[](int x)
{
	if (x < 0 || x >= list.getSize())
	{
		std::cerr << "Erro. Segmentation fault em EntityList::operator[]." << std::endl;
		exit(555);
	}

	return list[x];   //Operador [] sobrecarregado em List.h
}

void Lists::EntityList::destroyEntities()
{
	list.destroy();
}
