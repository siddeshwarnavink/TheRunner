#include <iostream>

#include "Game.h"
#include "State/GameState.h"
#include "Actor/MainCharacter.h"
#include "Entity/Floor.h"
#include "Generator/BlockGenerator.h"
#include "Static/SkyBackground.h"

bool Game::isColliding = false;

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jumping Game");
    if (!font.loadFromFile("./assets/font/Roboto-Black.ttf"))
    {
        std::cout << "Error: Failed to load Roboto-Black.ttf" << std::endl;
        return;
    }

    Actor::MainCharacter player;
    Entity::Floor floor(player);
    State::GameState gameState(window, player);
    Static::SkyBackground background(window);
    Generator::BlockGenerator blockGenerator(player, floor, window);

    float movementVelocity;

    sf::Clock clock;
    float targetFPS = 2000.0f;
    sf::Time frameTime = sf::seconds(1.0f / targetFPS);

    // Game loop
    while (window.isOpen())
    {

        sf::Time elapsed = clock.restart();
        if (elapsed < frameTime)
        {
            sf::sleep(frameTime - elapsed);
            elapsed = frameTime;
        }

        window.clear();
        background.draw();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        movementVelocity = 0.0f;
        this->isColliding = false;

        blockGenerator.loop();
        floor.loop();
        gameState.getPlayer().loop();

        if (gameState.getPlayer().getState() != Actor::PlayerState::DEAD)
        {
            // Movement logic
            movementVelocity = 0.2f;
            blockGenerator.move(-movementVelocity, 0.0f);
            floor.move(-movementVelocity, 0.0f);

            // Gravity
            if (isColliding)
            {
                gameState.getPlayer().setState(Actor::PlayerState::RUNNING);
                gameState.getPlayer().move(0.0f, 0.0f);
            }
            else if (gameState.getPlayer().getState() != Actor::PlayerState::JUMPING)
            {
                gameState.getPlayer().setState(Actor::PlayerState::FALLING);
                gameState.getPlayer().move(0.0f, 0.2f);
            }

            gameState.getPlayer().display(window);
        }
        blockGenerator.display();
        floor.display(window);
        window.display();
    }
}