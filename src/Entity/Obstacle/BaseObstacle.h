#pragma once

#include <SFML/Graphics.hpp>

#include "Entity/BaseEntity.h"
#include "Actor/MainCharacter.h"

namespace Entity::Obstacle
{
    class BaseObstacle : public BaseEntity
    {
    public:
        BaseObstacle(Actor::MainCharacter &mainCharacter);
        virtual void loop();
    };
}
