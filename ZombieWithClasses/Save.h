#ifndef ZOMBIEWITHCLASSES_SAVE_H
#define ZOMBIEWITHCLASSES_SAVE_H

#include "Serialize.h"

class Save : public Serialize {
public:
    virtual ~Save() {}

    bool save(const std::string& path);

    virtual void load(const std::string& path) = 0;
};

#endif //ZOMBIEWITHCLASSES_SAVE_H
