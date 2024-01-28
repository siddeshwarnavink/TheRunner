#include "Obstacle/Floor.h"
#include "Obstacle/BaseObstacle.h"
#include "Actor/MainCharacter.h"

namespace Obstacle {
    Floor::Floor(Actor::MainCharacter& mainCharacter) : BaseObstacle(mainCharacter) {
        obstacle.setSize(sf::Vector2f(5000.0f,10.0f));
        obstacle.setPosition(-500.0f,380.0f);
    }
}