#include "Actor/MainCharacter.h"

namespace Actor
{
    sf::Sprite charactersprite;

    MainCharacter::MainCharacter() : state(PlayerState::FALLING), jumpHeight(130.0f), spriteRegion(228, 36, 24, 24)
    {
        if (!texture.loadFromFile("./assets/texture/entity/main-character.png"))
        {
            return;
        }
        charactersprite.setTexture(texture);
        charactersprite.setPosition(10.0f, 10.0f);
        charactersprite.setTextureRect(spriteRegion);
        charactersprite.setScale(3.5f, 3.5f);
        initialPosition = charactersprite.getPosition();
    }

    void MainCharacter::display(sf::RenderWindow &window)
    {
        window.draw(charactersprite);
    }

    void MainCharacter::loop()
    {
        if (state != PlayerState::DEAD)
        {
            // Jump logic
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && state == PlayerState::RUNNING) || state == PlayerState::JUMPING)
            {

                if (charactersprite.getPosition().y >= jumpHeight)
                {
                    state = PlayerState::JUMPING;
                    charactersprite.move(0.0f, -0.15f);
                }
                else
                {
                    state = PlayerState::FALLING;
                }
            }
            else
            {
                initialPosition = charactersprite.getPosition();
                charactersprite.move(0.0f, 0.0f);
            }
        }

        // Void kill
        if (charactersprite.getPosition().y >= 500.f)
        {
            state = PlayerState::DEAD;
        }
    }

    void MainCharacter::move(float x, float y)
    {
        charactersprite.move(x, y);
    }

    sf::FloatRect MainCharacter::getGlobalBounds()
    {
        return charactersprite.getGlobalBounds();
    }

    sf::Vector2f MainCharacter::getPosition()
    {
        return charactersprite.getPosition();
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
