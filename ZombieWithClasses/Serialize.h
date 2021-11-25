//
// Created by Gabriel on 23/11/2021.
//

#ifndef ZOMBIEWITHCLASSES_SERIALIZE_H
#define ZOMBIEWITHCLASSES_SERIALIZE_H
#include "json.hpp"

class Serialize {
public:
    virtual ~Serialize() = default;
    virtual nlohmann::json convertJSON() = 0;
};


#endif //ZOMBIEWITHCLASSES_SERIALIZE_H
