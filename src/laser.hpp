#pragma once
#include <raylib.h>

class Laser
{
public:
    Laser(Vector2 nsposition, int speed);
    ~Laser();
    void draw();
    void update();
    bool alive;

private:
    Vector2 position;
    int speed;
    Texture2D lasersprite;
};