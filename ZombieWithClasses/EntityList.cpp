#include "EntityList.h"
#include "CollisionManager.h"

Lists::EntityList::EntityList() :
    list() {

}

Lists::EntityList::~EntityList() {
    list.destroy();
}

void Lists::EntityList::insert(Entities::Entity* pE) {
    list.insert(pE);
}

void Lists::EntityList::remove(Entities::Entity* pE) {
    list.remove(pE);
}

int Lists::EntityList::getSize() {
    return list.getSize();
}

void Lists::EntityList::update(float t)
{    
    for (int i = 0; i < list.getSize(); i++)
    {
        list[i]->update(t);
        if (!list[i]->getIsActive()) {
            remove(list[i]);
        }
    }
}

void Lists::EntityList::initialize(Managers::GraphicManager* GM, Managers::EventManager* EM,
    Managers::CollisionManager* CM) {
    for (int i = 0; i < list.getSize(); i++)
        list[i]->initialize(GM, EM, CM);
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

nlohmann::json Lists::EntityList::convertJSON() {
    nlohmann::json js = nlohmann::json::array();
    int pos = 0;
    Entities::Entity* e = list.backStart();
    while (e) {
        js[pos++] = e->convertJSON();
        e = list.goNext();
    }
    return js;
}
