/**
 * main character
 */

#pragma once

#include <stdint.h>

class Player
{
public:
    Player(int x, int y);

    void render();
    
    void update(int32_t tick);

private:
    int32_t gx_, gy_; // grid coordinates
    int32_t px_, py_; // pixel position, animates to catch up with grid coordinates * TILE_SIZE
    int32_t const updatePeriod_ = 1;

    bool move_(int dx, int dy);
};
