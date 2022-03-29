
#pragma once

#include "sprites.hpp"
#include "wasm4.h"
#include <stdint.h>

namespace map {

/**
 * Foreground is made of objects, attached to each screen
 */
// class Object
// {
//     // called to check if can walk into this tile
//     virtual bool passable()=0;
    
//     // called when entering the tile (if passable) or bumping (if not passable)
//     virtual void interact()=0;

//     // called to check what sprite to draw. cycle allows for animation
//     virtual uint8_t sprite(int cycle)=0;

//     // place data into ptr and increment it
//     virtual void store(uint8_t ** ptr)=0;

//     // load data from ptr and increment it
//     virtual void load(uint8_t ** ptr)=0;
// };

// class Screen
// {
//     // list of objects
// };

/**
 *  first checks object list, then tile
 * @param sx screen coord
 * @param sy screen coord
 */
void render(uint8_t sx, uint8_t sy, uint32_t tick);

/**
 *  first checks object list, then tile
 * @param gx global tile coord
 * @param gy global tile coord
 * @param returns true if passable
 */
bool interact(int gx, int gy);


} // namespace map