#include "State/GameState.h"

namespace State
{
    GameState::GameState(sf::RenderWindow &window, Actor::MainCharacter &player) : window(window), player(player)
    {
    }

    Actor::MainCharacter &GameState::getPlayer()
    {
        return player;
    }

    sf::RenderWindow &GameState::getWindow()
    {
        return window;
    }
}