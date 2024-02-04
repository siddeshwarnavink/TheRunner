#include <iostream>

#include "Entity/BaseEntity.h"
#include "Actor/MainCharacter.h"
#include "Game.h"

namespace Entity
{
    sf::RectangleShape texture;

    BaseEntity::BaseEntity(Actor::MainCharacter &player) : player(player)
    {
    }

    bool BaseEntity::isColliding()
    {
        sf::FloatRect mainCharacterBounds = player.getGlobalBounds();
        sf::FloatRect obstacleBounds = entitySprite.getTexture() == nullptr ? texture.getGlobalBounds() : entitySprite.getGlobalBounds();
        return mainCharacterBounds.intersects(obstacleBounds);
    }

    void BaseEntity::loop()
    {
        if (entitySprite.getTexture() == nullptr)
        {
            position = texture.getPosition();
        }
        else
        {
            position = entitySprite.getPosition();
        }

        // Collision
        Game::isColliding = !Game::isColliding && isColliding();
    }

    void BaseEntity::display(sf::RenderWindow &window)
    {
        if (entitySprite.getTexture() == nullptr)
        {
            window.draw(texture);
        }
        else
        {
            window.draw(entitySprite);
        }
    }

    void BaseEntity::move(float x, float y)
    {
        if (entitySprite.getTexture() == nullptr)
        {
            texture.move(x, y);
        }
        else
        {
            entitySprite.move(x, y);
        }
    }
}
