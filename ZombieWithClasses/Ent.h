#pragma once
#include "Ids.h"
#include "GraphicManager.h"

class Ent
{
protected:
    static Managers::GraphicManager* GM;
    Ids::Ids ID;
    const char* textPath;

public:

    Ent(Ids::Ids id = Ids::empty, const char* txtPath = nullptr);
    ~Ent();
    virtual void update(float t) = 0;
    static void setGM(Managers::GraphicManager* gm) { GM = gm; }
    Ids::Ids getID() { return ID; }
    const char* getTextPath() { return textPath; }
};