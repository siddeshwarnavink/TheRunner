#pragma once

#include <SFML/Graphics.hpp>

#include "entity/Actor/MainCharacter.h"
#include "entity/Obstacle/BaseObstacle.h"

namespace Entity::Obstacle {
    class Block: public BaseObstacle {
        public:
            Block(Actor::MainCharacter& mainCharacter);
    };
}