#pragma once

#include <SFML/Graphics.hpp>

#include "Actor/MainCharacter.h"
#include "Entity/BaseEntity.h"

namespace Entity
{
    class Floor : public BaseEntity
    {
    public:
        Floor(Actor::MainCharacter &mainCharacter);
        void loop() override;
        sf::RectangleShape get();
    };
}