
#pragma once

#include "sprites.hpp"
#include "wasm4.h"
#include <stdint.h>

namespace map {

/**
 * Foreground is made of objects, attached to each screen
 */
class Object
{
    // called to check if can walk into this tile
    virtual bool passable()=0;
    
    // called when entering the tile (if passable) or bumping (if not passable)
    virtual void interact()=0;

    // called to check what sprite to draw. cycle allows for animation
    virtual uint8_t sprite(int cycle)=0;

    // place data into ptr and increment it
    virtual void store(uint8_t ** ptr)=0;

    // load data from ptr and increment it
    virtual void load(uint8_t ** ptr)=0;
};

class Screen
{
    // todo list of objects
};

// draw current screen
void draw();

// first checks object list, then tile
void interact(uint8_t i, uint8_t j);

// returns which screen we are on
void getScreen(uint8_t &si, uint8_t &sj);

// sets which screen we are on
void setScreen(uint8_t si, uint8_t sj);


} // namespace map