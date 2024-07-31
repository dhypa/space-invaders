#include <raylib.h>
#include "player.hpp"
#include "gamecontainer.hpp"
#include <iostream>

GameContainer::GameContainer() {
    obstacles = createObstacles();
    invaders = createInvaders();
}
GameContainer::~GameContainer() {
}
void GameContainer::draw() {
    player.draw();

    for (Laser& laser : player.lasers)
    {
        laser.draw();
    }
    for (Obstacle& obstacle : obstacles)
    {
        obstacle.draw();
    }
    for (Invader& invader : invaders) {
        invader.draw();
    }

}

void GameContainer::handleInput() {
    if (IsKeyDown(KEY_SPACE))
    {
        player.shootLaser();
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        player.moveLeft();
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        player.moveRight();
    }
}

void GameContainer::deleteInactiveLasers() {
    for (auto it = player.lasers.begin(); it != player.lasers.end();)
    {
        if (!it->alive)
        {
            it = player.lasers.erase(it);
        }
        else
        {
            ++it;
        }
    };
}

void GameContainer::update() {
    for (Laser& laser : player.lasers)
    {

        laser.update();
    };
    deleteInactiveLasers();
}

std::vector<Obstacle> GameContainer::createObstacles() {
    int obstacleWidth = Obstacle::grid[0].size() * 3;
    float spacing = (GetScreenWidth() - (4 * obstacleWidth)) / 5;

    for (int i = 0; i < 4; i++)
    {
        float pos_x = (i + 1) * spacing + i * obstacleWidth;
        obstacles.push_back(Obstacle({ pos_x, float(GetScreenHeight() - 100) }));
    }

    return obstacles;
}

std::vector<Invader> GameContainer::createInvaders() {
    std::vector<Invader> invaders;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 11; col++) {
            float y = 50 + row * 46;
            float x = 86 + col * 50;
            int invaderType;
            if (row < 3) {
                invaderType = 1;
            }
            else if (row < 5) {
                invaderType = 2;
            }
            else {
                invaderType = 3;
            }
            invaders.push_back(Invader(invaderType, { x,y }));
        }

    }
    return invaders;
}
