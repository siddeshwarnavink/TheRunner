#pragma once

#include <SFML/Graphics.hpp>

#include "Actor/MainCharacter.h"
#include "Obstacle/BaseObstacle.h"

namespace Obstacle {
    class Floor: public BaseObstacle {
        public:
            Floor(Actor::MainCharacter& mainCharacter);
            void loop() override;
    };
}