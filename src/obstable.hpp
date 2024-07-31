#pragma once
#include <vector>
#include "block.hpp"

class Obstacle
{
public:
    Obstacle(Vector2 position);
    Vector2 position;
    void draw();
    std::vector<Block> blocks;
    static std::vector<std::vector<int>> grid;

private:
};
