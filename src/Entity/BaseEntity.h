#pragma once

#include <SFML/Graphics.hpp>

#include "State/GameState.h"
#include "Actor/MainCharacter.h"

namespace Entity
{
    class BaseEntity
    {
    protected:
        Actor::MainCharacter &player;
        sf::RectangleShape texture;
        bool isColliding();

    public:
        BaseEntity(Actor::MainCharacter &player);
        virtual void loop();
        void move(float x, float y);
        void display(sf::RenderWindow &window);
    };
};
