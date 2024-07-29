#pragma once
#include <raylib.h>
#include <vector>
#include "laser.hpp"

class Player
{
public:
    Player();
    ~Player();
    void update();
    void draw();
    void moveRight();
    void moveLeft();
    void shootLaser();
    std::vector<Laser> lasers;

private:
    Vector2 position;
    Texture2D shipSprite;
    int speed;
    double timeSinceLastLaser;
};