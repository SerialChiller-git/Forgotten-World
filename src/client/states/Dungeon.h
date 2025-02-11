#pragma once
#include "State.h"
#include <random>

enum Tile { WALL, FLOOR };

class Dungeon {
public:
    int width, height;
    std::vector<std::vector<Tile>> map;

    Dungeon(int w, int h) : width(w), height(h) {
        map.resize(height, std::vector<Tile>(width, WALL));
    }
    
};