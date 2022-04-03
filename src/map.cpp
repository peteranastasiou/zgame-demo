#include "map.hpp"
#include "objects.hpp"
#include "map.impl.auto.hpp"
#include "config.hpp"
#include "sprites.hpp"

/**
 * puzzles to test system:
 * SINGLE OBJECT:
 *  - light sconce
 *  - 
 *  - pick up into inventory (todo)
 *  - obstacle e.g. mob or ability check - triggers screen, then changes object
 *  - interaction triggers "animation" e.g. moving obstacle
 *  - warps
 *  - picking up treasure causes mob to appear OR recorded in blackboard that a mob is hunting you
 * MANY TO ONE:
 *  - light all sconces to get a pickup appear, when get pickup, door is unlocked
 * ONE TO MANY:
 *  - destruction of statue causes cultists to flee
 *  - opening one sarcophagus causes all to open
 * 
 * 
 * TODO expand objects array out to a map at runtime to reduce comparisons?
 * 
 */

namespace map {

Sconce sconce1;

static Object * const OBJECTS[]= {
    &sconce1
};

#define NUM_OBJECTS 1

void init() {
    sconce1.init(9, 4);
}

void render(int sx, int sy, uint32_t tick) {
    // origin (in tiles)
    int ox = sx*SCREEN_WIDTH;
    int oy = sy*SCREEN_HEIGHT;

    // draw background
    *DRAW_COLORS = 0x1234;
    for( int tx = 0; tx < SCREEN_WIDTH; ++tx ){
        for( int ty = 0; ty < SCREEN_HEIGHT; ++ty ){
            Tile tile = getTile(ox + tx, oy + ty);
            sprites::blit(tile.sprite, 16*tx, 16*ty);
        }
    }

    // animation cycle is slower than ticks
    int cycle = tick / 4;

    // draw foreground (objects)
    for( int objIdx = 0; objIdx < NUM_OBJECTS; ++objIdx ){
        Object * obj = OBJECTS[objIdx];
        // check if on current screen  -- TODO make this better
        if( obj->x <= ox 
         || obj->y <= oy
         || obj->x > ox+SCREEN_WIDTH 
         || obj->y > oy+SCREEN_HEIGHT ) continue;

        obj->render(cycle, ox, oy);
    }
}

// first checks object list, then tile
bool interact(int gx, int gy) {
    // check object first
    Object * obj = getObject(gx, gy);
    if( obj ){
        // check if passable first, in case interact() changes it
        bool passable = obj->passable();
        obj->interact();
        if( !passable ) return false;
    }

    // then check tile
    return getTile(gx, gy).passable;
}

Tile getTile(int gx, int gy) {
    if( gx < 0 || gy < 0 || gx >= MAP_WIDTH || gy >= MAP_HEIGHT){
        // should never happen
        return {};
    }

    uint8_t tile = TILES[gx + gy*MAP_WIDTH];
    // cast to Tile struct:
    return *(Tile*) &tile;
}

Object * getObject(int gx, int gy) {
    // TODO Expand to array so this is O(1) not O(n)
    for( Object * obj : OBJECTS ){
        if( obj->x == gx && obj->y == gy ){
            return obj;
        }
    }
    return nullptr;
}

} // namespace map
