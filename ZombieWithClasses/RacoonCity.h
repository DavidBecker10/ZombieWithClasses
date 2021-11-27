#ifndef ZOMBIEWITHCLASSES_RACOONCITY_H
#define ZOMBIEWITHCLASSES_RACOONCITY_H

#include "Stage.h"
#include "json.hpp"

namespace States
{
    class RacoonCity :
        public Stage
    {
    public:
        RacoonCity(Managers::GraphicManager* gm, Managers::ScreenManager* sm, Entities::Characters::PlayerOne* p1 = nullptr);
        nlohmann::json convertJSON() override;
        void load(const std::string& path) override;
        void initialize(bool numPlayers) override;
        //int execute() override;
    };
}

#endif //ZOMBIEWITHCLASSES_RACOONCITY_H