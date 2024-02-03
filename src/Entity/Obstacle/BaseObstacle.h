#pragma once

#include <SFML/Graphics.hpp>

#include "Entity/BaseEntity.h"
#include "Actor/MainCharacter.h"
#include "Entity/Floor.h"

namespace Entity::Obstacle
{
    class BaseObstacle : public BaseEntity
    {
    protected:
        Entity::Floor &floor;

    public:
        BaseObstacle(Actor::MainCharacter &player, Entity::Floor &floor);
        virtual void loop();
    };
}
