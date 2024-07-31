#pragma once
#include <raylib.h>

class Invader {
public:
    Invader(int type, Vector2 position);
    void update();
    void draw();
    int getType();
    void moveRight();
    void moveLeft();
    void shootLaser();
    Vector2 position;
    static Texture2D invaderImages[3];
    int type;

private:
};
