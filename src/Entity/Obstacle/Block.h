#pragma once

#include <SFML/Graphics.hpp>

#include "Entity/Obstacle/BaseObstacle.h"

namespace Entity::Obstacle
{
    class Block : public BaseObstacle
    {
    public:
        Block(Actor::MainCharacter &player, Entity::Floor &floor, float posX, float posY);
        void loop() override;
    };
}