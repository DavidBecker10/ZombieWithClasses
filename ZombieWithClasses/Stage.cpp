#include "Stage.h"

Stages::Stage::~Stage()
{
}

void Stages::Stage::update(float t)
{
    Elist->update(t);
}
