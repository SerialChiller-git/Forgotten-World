#pragma once
#include "State.h"
#include <random>

enum Tile { WALL, FLOOR };

class Dungeon {
public:
    int width, height;
    std::vector<std::vector<Tile>> map;

    Dungeon(int w, int h);

private:
    
};