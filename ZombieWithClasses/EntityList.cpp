#include "EntityList.h"
#include "CollisionManager.h"

Lists::EntityList::EntityList() :
    list() {

}

Lists::EntityList::~EntityList() {
    list.destroy();
}

void Lists::EntityList::insert(Entities::Entity* pE) {
    if (pE)
        list.insert(pE);
    else
        std::cout << "Erro: pE nulo em EntityList::insert" << std::endl;
}

void Lists::EntityList::remove(Entities::Entity* pE) {
    if (!list.remove(pE))
        std::cout << "Erro ao remover" << std::endl;
}

int Lists::EntityList::getSize() {
    return list.getSize();
}

void Lists::EntityList::update(float t) {
    for (int i = 0; i < list.getSize(); i++)
        list[i]->update(t);
}

void Lists::EntityList::initialize(Managers::EventManager* EM,
    Managers::CollisionManager* CM) {
    for (int i = 0; i < list.getSize(); i++)
        list[i]->initialize(EM, CM);
}

void Lists::EntityList::draw() {
    for (int i = 0; i < list.getSize(); i++)
        list[i]->draw();
}

Entities::Entity* Lists::EntityList::operator[](int x) {
    if (x < 0 || x >= list.getSize()) {
        std::cerr << "Erro. Segmentation fault em EntityList::operator[]." << std::endl;
        exit(555);
    }

    return list[x];   //Operador [] sobrecarregado em List.h
}

void Lists::EntityList::destroyEntities() {
    list.destroy();
}
