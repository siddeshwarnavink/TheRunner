#pragma once

#include <SFML/Graphics.hpp>

#include "Actor/MainCharacter.h"
#include "Obstacle/BaseObstacle.h"

namespace Obstacle {
    class Block: public BaseObstacle {
        public:
            Block(Actor::MainCharacter& mainCharacter, float posX, float posY);
            void loop() override;
    };
}