#include <iostream>

#include "Entity/Obstacle/BaseObstacle.h"
#include "Entity/BaseEntity.h"

namespace Entity::Obstacle
{
    BaseObstacle::BaseObstacle(Actor::MainCharacter &player, Entity::Floor &floor) : BaseEntity(player), floor(floor)
    {
    }

    void BaseObstacle::loop()
    {
        BaseEntity::loop();
        if (isColliding())
        {
            player.setState(Actor::PlayerState::DEAD);
        }
    }
}
