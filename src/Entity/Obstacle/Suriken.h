#pragma once

#include <SFML/Graphics.hpp>

#include "Entity/Obstacle/BaseObstacle.h"

namespace Entity::Obstacle
{
    class Suriken : public BaseObstacle
    {
    private:
        bool initialAnimationDone;
        int animtionCount;
        sf::Time elapsedTime;
        sf::Clock clock;
        static sf::Time animationInterval;
        sf::Texture surikenTexture;
        void animation();

    public:
        Suriken(Actor::MainCharacter &player, Entity::Floor &floor, float posX, float posY);
        void loop() override;
    };
}