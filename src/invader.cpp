#include "invader.hpp"
#include <raylib.h>
#include <iostream>

Texture2D Invader::invaderImages[3] = {};

Invader::Invader(int type, Vector2 position) {

    this->position = position;
    this->type = type;
    if (invaderImages[type - 1].id == 0) {
        switch (type) {
            case 1:
                invaderImages[0] = LoadTexture("sprites/invader_1.png");
                break;
            case 2:
                invaderImages[1] = LoadTexture("sprites/invader_2.png");
                break;
            case 3:
                invaderImages[2] = LoadTexture("sprites/invader_3.png");
                break;
            default:
                invaderImages[0] = LoadTexture("sprites/invader_1.png");
        }
    }
}


void Invader::draw() {
    DrawTextureV(invaderImages[type - 1], position, WHITE);
}
int Invader::getType() {
    return type;
}
