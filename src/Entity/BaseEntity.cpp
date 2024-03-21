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

    sf::Sprite BaseEntity::getSprite()
    {
        return entitySprite;
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
            if (texture.getPosition() != sf::Vector2f(0, 0))
            {
                if (texture.getPosition() != sf::Vector2f(0, 0))
                {
                    position = texture.getPosition();
                }
            }
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
            if (texture.getPosition() != sf::Vector2f(0, 0))
            {
                window.draw(texture);
            }
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
            if (texture.getPosition() != sf::Vector2f(0, 0))
            {
                texture.move(x, y);
            }
        }
        else
        {
            entitySprite.move(x, y);
        }
    }
}
