#include <iostream>

#include "Entity/Obstacle/Suriken.h"
#include "Entity/Obstacle/BaseObstacle.h"
#include "Actor/MainCharacter.h"

namespace Entity::Obstacle
{
    sf::Time Suriken::animationInterval = sf::seconds(0.05f);

    Suriken::Suriken(Actor::MainCharacter &player, Entity::Floor &floor, float posX, float posY) : BaseObstacle(player, floor), animtionCount(0)
    {
        if (!surikenTexture.loadFromFile("./assets/texture/entity/traps/suriken.png"))
        {
            std::cout << "Error: Failed to load suriken.png" << std::endl;
            exit(1);
        }

        entitySprite.setTexture(surikenTexture);
        entitySprite.setPosition(posX, floor.get().getPosition().y - entitySprite.getGlobalBounds().height);
        entitySprite.setScale(2.0f, 2.0f);

        sf::IntRect spriteRegion(0, 0, 30, 30);
        entitySprite.setTextureRect(spriteRegion);

        position = entitySprite.getPosition();
    }

    void Suriken::animation()
    {
        sf::IntRect spriteRegion;
        int updatedAnimtionCount = 0;
        switch (animtionCount)
        {
        case 0:
            spriteRegion = sf::IntRect(64, 0, 30, 30);
            updatedAnimtionCount = 1;
            break;
        case 1:
            spriteRegion = sf::IntRect(96, 0, 30, 30);
            updatedAnimtionCount = 2;
            break;
        case 2:
            spriteRegion = sf::IntRect(128, 0, 30, 30);
            updatedAnimtionCount = 4;
            break;
        case 4:
            spriteRegion = sf::IntRect(160, 0, 30, 30);
            updatedAnimtionCount = 5;
            break;
        case 5:
            spriteRegion = sf::IntRect(192, 0, 30, 30);
            updatedAnimtionCount = 6;
            break;
        case 6:
            spriteRegion = sf::IntRect(224, 0, 30, 30);
            updatedAnimtionCount = 7;
            break;
        default:
            spriteRegion = sf::IntRect(0, 0, 32, 32);
            break;
        }
        entitySprite.setTextureRect(spriteRegion);
        animtionCount = updatedAnimtionCount;
    }

    void Suriken::loop()
    {
        // Animtion
        elapsedTime += clock.restart();
        if (!initialAnimationDone)
        {
            animation();
            initialAnimationDone = true;
        }
        else if (elapsedTime >= animationInterval)
        {
            animation();
            elapsedTime = sf::Time::Zero;
        }

        BaseObstacle::loop();
    }
}