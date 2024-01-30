#include <iostream>

#include "Entity/Obstacle/BaseObstacle.h"
#include "Entity/BaseEntity.h"
#include "Actor/MainCharacter.h"
#include "Game.h"

namespace Entity::Obstacle
{
    sf::RectangleShape obstacle;

    BaseObstacle::BaseObstacle(Actor::MainCharacter &mainCharacter) : BaseEntity(mainCharacter)
    {
    }

    void BaseObstacle::loop()
    {
        BaseEntity::loop();
        if (isColliding())
        {
            mainCharacter.setState(Actor::PlayerState::DEAD);
        }
    }
}
