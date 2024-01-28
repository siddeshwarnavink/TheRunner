#include "Obstacle/Block.h"
#include "Obstacle/BaseObstacle.h"
#include "Actor/MainCharacter.h"

namespace Obstacle {
    Block::Block(Actor::MainCharacter& mainCharacter) : BaseObstacle(mainCharacter)  {
        obstacle.setSize(sf::Vector2f(50.0f, 50.0f));
        obstacle.setPosition(300.0f, 330.0f);
        obstacle.setFillColor(sf::Color::Red);
    }

    void Block::loop() {
        BaseObstacle::loop();
        if (isColliding()) {
            mainCharacter.setState(Actor::PlayerState::DEAD);
        }
    }
}