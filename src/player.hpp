/**
 * main character
 */

#pragma once

#include <stdint.h>

class Player
{
public:
    Player(int x, int y);

    void render(int32_t tick);
    
    void update(int32_t tick);

private:
    // position
    int32_t gx_, gy_; // grid coordinates
    int32_t px_, py_; // pixel position, animates to catch up with grid coordinates * TILE_SIZE
    int32_t const updatePeriod_ = 1;
    int32_t const animationPeriod_ = 8;

    // animation state
    bool walking_;
    int32_t step_, frame_;

    // facing direction
    enum Dir
    {
        N, E, S, W
    } dir_;

    bool move_(int dx, int dy);
};
