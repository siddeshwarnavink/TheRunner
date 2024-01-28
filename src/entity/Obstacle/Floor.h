#pragma once

#include <SFML/Graphics.hpp>

#include "entity/Actor/MainCharacter.h"
#include "entity/Obstacle/BaseObstacle.h"

namespace Entity::Obstacle {
    class Floor: public BaseObstacle {
        public:
            Floor(Actor::MainCharacter& mainCharacter);
    };
}