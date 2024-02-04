#include "Actor/MainCharacter.h"

namespace Actor
{
    sf::Sprite playerSprite;
    sf::Time MainCharacter::animationInterval = sf::seconds(0.15f);

    MainCharacter::MainCharacter() : state(PlayerState::FALLING), jumpHeight(130.0f), animationCount(1), initialAnimationDone(false)
    {
        if (!texture.loadFromFile("./assets/texture/entity/main-character.png"))
        {
            return;
        }
        playerSprite.setTexture(texture);
        playerSprite.setPosition(10.0f, 10.0f);
        sf::IntRect spriteRegion(197, 36, 24, 24);
        playerSprite.setTextureRect(spriteRegion);
        playerSprite.setScale(3.5f, 3.5f);
        initialPosition = playerSprite.getPosition();
    }

    void MainCharacter::display(sf::RenderWindow &window)
    {
        window.draw(playerSprite);
    }

    void MainCharacter::playerAnimation()
    {
        sf::IntRect spriteRegion;

        switch (state)
        {
        case PlayerState::JUMPING:
            spriteRegion = sf::IntRect(36, 36, 24, 24);
            break;
        case PlayerState::FALLING:
            spriteRegion = sf::IntRect(98, 36, 24, 24);
            break;
        default:
            if (animationCount == 1)
            {
                spriteRegion = sf::IntRect(228, 36, 24, 24);
                animationCount = 2;
            }
            else if (animationCount == 2)
            {
                spriteRegion = sf::IntRect(197, 36, 24, 24);
                animationCount = 1;
            }
            break;
        }

        playerSprite.setTextureRect(spriteRegion);
    }

    void MainCharacter::loop()
    {
        // Animtion
        elapsedTime += clock.restart();
        if (!initialAnimationDone)
        {
            playerAnimation();
            initialAnimationDone = true;
        }
        else if (elapsedTime >= animationInterval)
        {
            playerAnimation();
            elapsedTime = sf::Time::Zero;
        }

        if (state != PlayerState::DEAD)
        {
            // Jump logic
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && state == PlayerState::RUNNING) || state == PlayerState::JUMPING)
            {

                if (playerSprite.getPosition().y >= jumpHeight)
                {
                    state = PlayerState::JUMPING;
                    playerSprite.move(0.0f, -0.15f);
                }
                else
                {
                    state = PlayerState::FALLING;
                }
            }
            else
            {
                initialPosition = playerSprite.getPosition();
                playerSprite.move(0.0f, 0.0f);
            }
        }

        // Void kill
        if (playerSprite.getPosition().y >= 500.f)
        {
            state = PlayerState::DEAD;
        }
    }

    void MainCharacter::move(float x, float y)
    {
        playerSprite.move(x, y);
    }

    sf::FloatRect MainCharacter::getGlobalBounds()
    {
        return playerSprite.getGlobalBounds();
    }

    sf::Vector2f MainCharacter::getPosition()
    {
        return playerSprite.getPosition();
    }

    void MainCharacter::setState(PlayerState state)
    {
        this->state = state;
    }

    PlayerState MainCharacter::getState()
    {
        return this->state;
    }
}
