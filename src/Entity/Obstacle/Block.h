#pragma once

#include <SFML/Graphics.hpp>

#include "Actor/MainCharacter.h"
#include "Entity/Floor.h"
#include "Entity/Obstacle/BaseObstacle.h"

namespace Entity::Obstacle
{
    class Block : public BaseObstacle
    {
    public:
        Block(Actor::MainCharacter &mainCharacter, Entity::Floor &floor, float posX, float posY);
        void loop() override;
    };
}