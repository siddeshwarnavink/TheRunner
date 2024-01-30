#pragma once

#include <SFML/Graphics.hpp>

#include "Entity/BaseEntity.h"
#include "Entity/Floor.h"
#include "Actor/MainCharacter.h"

namespace Entity::Obstacle
{
    class BaseObstacle : public BaseEntity
    {
    protected:
        Entity::Floor &floor;

    public:
        BaseObstacle(Actor::MainCharacter &mainCharacter, Entity::Floor &floor);
        virtual void loop();
    };
}
