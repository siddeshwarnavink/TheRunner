#pragma once

#include <SFML/Graphics.hpp>

#include "Entity/BaseEntity.h"

namespace Entity
{
    namespace FloorComponents
    {
        enum FloorVariant
        {
            FLAT,
            DECLINE,
            INCLINE,
            DECLINE_FLAT
        };

        class FloorTile
        {
        private:
            sf::Sprite tileSprite;
            FloorVariant type;

        public:
            FloorTile(sf::Sprite tileSprite, FloorVariant type);
            sf::Sprite &getTileSprite();
        };

    }

    class Floor : public BaseEntity
    {
    private:
        static const int floorCount;
        sf::Texture tileTexture;
        std::vector<FloorComponents::FloorTile *> floorTiles;
        void initializeTiles();

    protected:
        bool isColliding();

    public:
        Floor(Actor::MainCharacter &player);
        ~Floor();
        void loop();
        void display(sf::RenderWindow &window);
        void move(float x, float y);
        sf::Sprite get();
    };
}