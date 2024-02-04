#include <iostream>

#include "Game.h"

const float targetFPS = 2000.0f;
bool Game::running = false, Game::isColliding = false;

Game::Game() : window(sf::VideoMode(800, 600), "Jumping Game"),
               floor(player),
               gameState(window, player),
               background(window),
               blockGenerator(player, floor, window),
               frameTime(sf::seconds(1.0f / targetFPS))
{
    if (running)
    {
        std::cout << "Error: Game is already running" << std::endl;
        exit(0);
    }
    running = true;
}

void Game::loadAssets()
{
    if (!font.loadFromFile("./assets/font/Roboto-Black.ttf"))
    {
        std::cout << "Error: Failed to load Roboto-Black.ttf" << std::endl;
        exit(1);
    }
}

void Game::exitWindow()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Game::fpsLock()
{
    sf::Time elapsed = fpsClock.restart();
    if (elapsed < frameTime)
    {
        sf::sleep(frameTime - elapsed);
        elapsed = frameTime;
    }
}

void Game::playerPhysics()
{
    // Movement logic
    movementVelocity = 0.2f;
    blockGenerator.move(-movementVelocity, 0.0f);
    // floor.move(-movementVelocity, 0.0f);

    // Gravity
    if (isColliding)
    {
        player.setState(Actor::PlayerState::RUNNING);
        player.move(0.0f, 0.0f);
    }
    else if (player.getState() != Actor::PlayerState::JUMPING)
    {
        player.setState(Actor::PlayerState::FALLING);
        player.move(0.0f, 0.2f);
    }
}

void Game::run()
{
    loadAssets();

    // Game loop
    while (window.isOpen())
    {
        movementVelocity = 0.0f;
        this->isColliding = false;

        exitWindow();
        fpsLock();

        window.clear();
        background.draw();

        blockGenerator.loop();
        floor.loop();
        player.loop();

        if (player.getState() != Actor::PlayerState::DEAD)
        {
            playerPhysics();
            player.display(window);
        }
        blockGenerator.display();
        floor.display(window);
        window.display();
    }
}