#include <iostream>

#include "Static/SkyBackground.h"

namespace Static
{
    SkyBackground::SkyBackground(sf::RenderWindow &window) : window(window)
    {
        if (!backgroundTexture.loadFromFile("./assets/texture/background/sky.png"))
        {
            std::cout << "Error: Failed to load sky.png" << std::endl;
            return;
        }
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setPosition(0, 0);
        float scaleFactor = static_cast<float>(window.getSize().x) / backgroundSprite.getTexture()->getSize().x;
        backgroundSprite.setScale(scaleFactor, scaleFactor);
    }

    void SkyBackground::draw() {
        window.draw(backgroundSprite);
    }
}