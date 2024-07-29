#pragma once
#include <raylib.h>

class Invader
{
public:
    Invader(int x, int y);
    ~Invader();
    void update();
    void draw();
    void moveRight();
    void moveLeft();
    void shootLaser();

private:
    Vector2 position;
    Texture2D shipSprite;
};