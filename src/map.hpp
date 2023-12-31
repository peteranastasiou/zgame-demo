
#pragma once

#include "dir.hpp"
#include "sprites.hpp"
#include "wasm4.h"
#include <stdint.h>

namespace map {

// Map is made of a "tile" background layer and an "Object" foreground layer

class Object {
public:
    void setTriggered(bool triggered){ triggered_= triggered; }

    bool isTriggered(){ return triggered_; }

    // called to check if can walk into this tile
    virtual bool passable()=0;
    
    // called when entering the tile (if passable) or bumping (if not passable)
    virtual void interact()=0;

    // label
    virtual char const * getLabel(){
        return "";
    }

    // called to check what sprite to draw. 
    // cycle is slower than ticks and defines animation speed
    // x, y are tile coordinates on the current screen
    virtual void render(int cycle, int x, int y)=0;

protected:
    void render_(int sprite, int x, int y, uint32_t flags=0){
        sprites::blit(sprite, 16*x, 16*y, flags);
    }

    bool triggered_= false;
};

// ----------------------------------------------
// Map Functions
// ----------------------------------------------

void init();

/**
 * render the selected screen
 * @param sx screen coord
 * @param sy screen coord
 */
void render(int sx, int sy, uint32_t tick);

/**
 * Call a customisable per-room function
 * @param sx screen coord
 * @param sy screen coord
 */
void update(int sx, int sy, uint32_t tick);

/**
 *  first checks object list, then tile
 * @param gx global tile coord
 * @param gy global tile coord
 * @param returns true if passable
 */
bool interact(int gx, int gy, Dir dir);

/**
 * get tile type at location
 * @param gx global tile coord
 * @param gy global tile coord
 * @return tile type === sprite index of tile
 */
uint8_t getTile(int gx, int gy);

/**
 * check if tile type is passable from a certain direction
 * @param tileType type of tile
 * @param dir approach direction
 * @return true if passable
 */
bool isTilePassable(uint8_t tileType, Dir dir);

/**
 * get object
 * @param gx global tile coord
 * @param gy global tile coord
 */
Object * getObject(int gx, int gy);

} // namespace map