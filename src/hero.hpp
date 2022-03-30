/**
 * main character
 */

#pragma once

#include <stdint.h>

class Hero
{
public:
    Hero(int x, int y);

    void render(uint32_t tick);
    
    void update(uint32_t tick);

    int getX(){ return gxCurr_; }
    int getY(){ return gyCurr_; }

private:
    // position
    int32_t gxCurr_, gyCurr_; // global tile coordinate (if walking: exiting this tile)
    int32_t gxNext_, gyNext_; // global tile coordinates (if walking: entering this tile)
    int32_t px_, py_; // pixel position, animates to catch up with grid coordinates * TILE_SIZE
    uint32_t const updatePeriod_ = 1;
    uint32_t const animationPeriod_ = 8;

    // animation state
    bool walking_;
    uint32_t step_;
    int32_t frame_;

    // facing direction
    enum Dir
    {
        N, E, S, W
    } dir_;

    void move_(int dx, int dy);
};
