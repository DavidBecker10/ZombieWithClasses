#pragma once
#include "Character.h"
#include "Player.h"
namespace Entities
{
    namespace Characters
    {
        class Enemy :
            public Character
        {
        protected:
            Player* player1;

        public:
            Enemy(Vector2F pos = { 0.0f, 0.0f }, Ids::Ids id = Ids::Ids::empty, const char* tPath = nullptr, int lf = 0, Player* p1 = nullptr);
            ~Enemy();
            virtual void initialize(Managers::GraphicManager* GM, Managers::EventManager* EM, Managers::CollisionManager* CM);
            virtual void update(float t) = 0;
            void draw();
            virtual void collide(Ids::Ids idOther, Vector2F positionOther, Vector2F dimensionsOther);
            float distancePlayer();
            nlohmann::json convertJSON() override;
        };
    }
}
