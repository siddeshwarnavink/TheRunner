#pragma once

#include <SFML/Graphics.hpp>

namespace Actor
{
    enum PlayerState
    {
        RUNNING,
        DEAD,
        JUMPING,
        FALLING
    };

    class MainCharacter
    {
    private:
        int animationCount;
        sf::Clock clock;
        sf::Time elapsedTime;
        static sf::Time animationInterval;
        sf::Texture texture;
        sf::Sprite playerSprite;
        PlayerState state;
        float jumpHeight;
        void playerAnimation();
        bool initialAnimationDone;

    public:
        sf::Vector2f initialPosition;
        MainCharacter();
        void loop();
        void display(sf::RenderWindow &window);
        void move(float x, float y);
        sf::Vector2f getPosition();
        sf::FloatRect getGlobalBounds();
        void setState(PlayerState state);
        PlayerState getState();
    };
}
