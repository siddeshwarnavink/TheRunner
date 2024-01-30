#pragma once

#include <SFML/Graphics.hpp>

#include "Actor/MainCharacter.h"

namespace Entity
{
    class BaseEntity
    {
    protected:
        sf::RectangleShape texture;
        Actor::MainCharacter &mainCharacter;
        bool isColliding();

    public:
        BaseEntity(Actor::MainCharacter &mainCharacter);
        virtual void loop();
        void move(float x, float y);
        void display(sf::RenderWindow &window);
    };
};
