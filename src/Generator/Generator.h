#pragma once

#include <memory>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "State/GameState.h"
#include "Entity/Obstacle/BaseObstacle.h"
#include "Actor/MainCharacter.h"
#include "Entity/Floor.h"

namespace Generator
{
    class Generator
    {
    private:
        float spawningProbability;
        sf::Clock clock;
        sf::Time elapsedTime;
        static sf::Time interval;
        void generateObstacle();

    protected:
        Actor::MainCharacter &player;
        Entity::Floor &floor;
        sf::RenderWindow &window;
        std::vector<Entity::Obstacle::BaseObstacle *> obstacleList;
        virtual Entity::Obstacle::BaseObstacle *generate(float xPos, float yPos);

    public:
        Generator(Actor::MainCharacter &player, Entity::Floor &floor, sf::RenderWindow &window);
        ~Generator();
        void setSpawningProbability(float probability);
        void loop();
        void display();
        void move(float x, float y);
    };
};