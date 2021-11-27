#ifndef ZOMBIEWITHCLASSES_SUBWAY_H
#define ZOMBIEWITHCLASSES_SUBWAY_H

#include "Stage.h"

namespace States
{
    class Subway :
        public Stage
    {
    public:
        Subway(Managers::GraphicManager* gm, Managers::ScreenManager* sm, Entities::Characters::PlayerOne* p1 = nullptr);
        nlohmann::json convertJSON() override;
        void load(const std::string& path) override;
        void initialize(bool numPlayers) override;
        //int execute() override;
    };
}

#endif //ZOMBIEWITHCLASSES_SUBWAY_H