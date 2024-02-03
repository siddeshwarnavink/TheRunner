#pragma once

#include <SFML/Graphics.hpp>

#include "Entity/BaseEntity.h"

namespace Entity
{
    class Floor : public BaseEntity
    {
    public:
        Floor(Actor::MainCharacter &player);
        void loop() override;
        sf::RectangleShape get();
    };
}