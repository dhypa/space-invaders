#include <raylib.h>
#include "gamecontainer.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime> 

GameContainer::GameContainer() {
    obstacles = createObstacles();
    invaders = createInvaders();
    invaderDirection = 1;
    timeSinceLastInvaderFired = 0;
}
GameContainer::~GameContainer() {
    Invader::unloadImages();
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
    for (Laser& laser : invaderLasers)
    {
        laser.draw();
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
    for (auto it = player.lasers.begin(); it != player.lasers.end();) {
        if (!it->alive) {
            it = player.lasers.erase(it);
        }
        else {
            ++it;
        }
    }
    for (auto it = invaderLasers.begin(); it != invaderLasers.end();) {
        if (!it->alive) {
            it = invaderLasers.erase(it);
        }
        else {
            ++it;
        }
    };
}

void GameContainer::update() {
    for (Laser& laser : player.lasers) {
        laser.update();
    };
    for (Laser& laser : invaderLasers) {
        laser.update();
    }
    fireInvaderLaser();
    moveInvaders();
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
            if (row == 1 || row == 0) {
                invaderType = 1;
            }
            else if (row == 2 || row == 3) {
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

void GameContainer::moveInvaders() {
    for (auto& invader : invaders) {
        if (invader.position.x + 40 > GetScreenWidth()) {
            invaderDirection = -1;
            moveDownInvaders(4);
        }
        else if (invader.position.x < 0) {
            invaderDirection = 1;
            moveDownInvaders(4);
        }

        invader.update(invaderDirection);
    }

}

void GameContainer::moveDownInvaders(int displacement) {
    for (auto& invader : invaders) {
        invader.position.y += displacement;
    }
}

void GameContainer::fireInvaderLaser() {
    double time = GetTime();

    if (time - timeSinceLastInvaderFired > invaderFireLaserInterval && !invaders.empty()) {
        int i = GetRandomValue(0, invaders.size() - 1);
        invaderLasers.push_back(Laser({ invaders[i].position.x + 20,invaders[i].position.y + 20 }, -6));
        timeSinceLastInvaderFired = time;
    }
}
