#include <iostream>

#include "Entity/BaseEntity.h"
#include "Actor/MainCharacter.h"
#include "Game.h"

namespace Entity {
    sf::RectangleShape texture;

    BaseEntity::BaseEntity(Actor::MainCharacter& mainCharacter) : mainCharacter(mainCharacter)  {
    }

    bool BaseEntity::isColliding() {
        sf::FloatRect mainCharacterBounds = mainCharacter.getGlobalBounds();
        sf::FloatRect obstacleBounds = texture.getGlobalBounds();
        return mainCharacterBounds.intersects(obstacleBounds);
    }

    void BaseEntity::loop() {
        // Collision
        Game::isColliding = !Game::isColliding && isColliding();
    }


    void BaseEntity::display(sf::RenderWindow& window) {
        window.draw(texture);
    }

    void BaseEntity::move(float x, float y) {
        texture.move(x, y);
    }
}
