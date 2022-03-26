
#pragma once

#include <stdint.h>

namespace map {

struct Tile
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

/**
 * @param tx tile coordinates from 0 to 160
 * @param ty tile coordinates from 0 to 160
 * @return Tile* 
 */
Tile * get(uint8_t x, uint8_t y);


} // namespace map