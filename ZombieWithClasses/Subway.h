#ifndef ZOMBIEWITHCLASSES_SUBWAY_H
#define ZOMBIEWITHCLASSES_SUBWAY_H


#include "Stage.h"

namespace States
{
    class Subway :
        public Stage
    {
    public:
        Subway(Managers::GraphicManager* gm, Entities::Characters::Player* p1 = nullptr);
        nlohmann::json convertJSON() override;
        void load(const std::string& path) override;
        void initialize(bool twoPlayers) override;

    };
}


#endif //ZOMBIEWITHCLASSES_SUBWAY_H
