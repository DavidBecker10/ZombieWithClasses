#include "Ent.h"

Ent::Ent(Ids::Ids id, const char* txtPath) :
    ID(id),
    textPath(txtPath)
{
}

Ent::~Ent() {
}


Managers::GraphicManager* Ent::GM = NULL;