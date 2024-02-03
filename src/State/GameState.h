#pragma once

#include <SFML/Graphics.hpp>

#include "Actor/MainCharacter.h"

namespace State
{
    class GameState
    {
    private:
        sf::RenderWindow &window;
        Actor::MainCharacter &player;

    public:
        GameState(sf::RenderWindow &window, Actor::MainCharacter &player);
        Actor::MainCharacter &getPlayer();
        sf::RenderWindow &getWindow();
    };
};