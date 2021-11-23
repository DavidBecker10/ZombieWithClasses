#include "Ent.h"

Ent::Ent(Ids::Ids id, const char* txtPath) :
    ID(id),
    textPath(txtPath)
{
}

Ent::~Ent() {
}

void Ent::print() {
}

Managers::GraphicManager* Ent::GM = NULL;