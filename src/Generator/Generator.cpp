#include <random>

#include "Generator/Generator.h"

namespace Generator
{
    sf::Time Generator::interval = sf::seconds(1.0f);

    Generator::Generator(Actor::MainCharacter &player, Entity::Floor &floor, sf::RenderWindow &window) : player(player), floor(floor), window(window)
    {
    }

    Generator::~Generator()
    {
        for (Entity::Obstacle::BaseObstacle *obstaclePtr : obstacleList)
        {
            delete obstaclePtr;
        }
        obstacleList.clear();
    }

    Entity::Obstacle::BaseObstacle *Generator::generate(float xPos, float yPos)
    {
        return nullptr;
    }

    void Generator::generateObstacle()
    {
        float minX = player.getPosition().x + 500.0f;
        float maxX = minX + 100.0f;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> Xdist(minX, maxX);

        float randomX = Xdist(gen);

        Entity::Obstacle::BaseObstacle *obstacle = generate(randomX, player.initialPosition.y + player.getGlobalBounds().height - 30.0f);
        if (obstacle)
        {
            obstacleList.push_back(obstacle);
        }
    }

    void Generator::loop()
    {
        for (Entity::Obstacle::BaseObstacle *obstaclePtr : obstacleList)
        {
            if (obstaclePtr)
            {
                obstaclePtr->loop();
            }
        }

        elapsedTime = clock.getElapsedTime();
        if (elapsedTime >= interval)
        {
            generateObstacle();
            clock.restart();
        }
    }

    void Generator::display()
    {
        for (Entity::Obstacle::BaseObstacle *obstaclePtr : obstacleList)
        {
            obstaclePtr->display(window);
        }
    }

    void Generator::move(float x, float y)
    {
        for (Entity::Obstacle::BaseObstacle *obstaclePtr : obstacleList)
        {
            obstaclePtr->move(x, y);
        }
    }
}