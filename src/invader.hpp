#pragma once
#include <raylib.h>

class Invader {
public:
    Invader(int type, Vector2 position);
    void update();
    void draw();
    void update(int direction);
    int getType();
    void moveRight();
    void moveLeft();
    static void unloadImages();
    Vector2 position;
    static Texture2D invaderImages[3];
    int type;

private:
};
