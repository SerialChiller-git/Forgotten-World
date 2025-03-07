#include "Dungeon.h"

Dungeon::Dungeon(int w, int h) : width(w), height(h) {
    map.resize(height, std::vector<Tile>(width, WALL));
}



