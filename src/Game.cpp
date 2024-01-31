#include <iostream>

#include "Game.h"
#include "Actor/MainCharacter.h"
#include "Entity/Floor.h"
#include "Generator/BlockGenerator.h"

bool Game::isColliding = false;

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jumping Game");
    if (!font.loadFromFile("./assets/font/Roboto-Black.ttf"))
    {
        std::cout << "Error: Failed to load Roboto-Black.ttf" << std::endl;
        return;
    }

    // Backgroud image
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    if (!backgroundTexture.loadFromFile("./assets/texture/background/sky.png"))
    {
        std::cout << "Error: Failed to load sky.png" << std::endl;
        return;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);
    float scaleFactor = static_cast<float>(window.getSize().x) / backgroundSprite.getTexture()->getSize().x;
    backgroundSprite.setScale(scaleFactor, scaleFactor);

    Actor::MainCharacter player;
    Entity::Floor floor(player);
    Generator::BlockGenerator blockGenerator(window, player, floor);

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
        window.draw(backgroundSprite);

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
        player.loop();

        if (player.getState() != Actor::PlayerState::DEAD)
        {
            // Movement logic
            movementVelocity = 0.2f;
            blockGenerator.move(-movementVelocity, 0.0f);
            floor.move(-movementVelocity, 0.0f);

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

            player.display(window);
        }
        blockGenerator.display();
        floor.display(window);
        window.display();
    }
}