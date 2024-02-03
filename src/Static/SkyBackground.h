#include <SFML/Graphics.hpp>

namespace Static
{
    class SkyBackground
    {
    private:
        sf::RenderWindow &window;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

    public:
        SkyBackground(sf::RenderWindow &window);
        void draw();
    };
};
